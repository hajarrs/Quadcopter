/***************************************
 * 
 * Android Bluetooth Dual Joystick
 * yus - projectproto.blogspot.com
 * October 2012
 *  
 ***************************************/

package org.projectproto.btjoystick;

import com.MobileAnarchy.Android.Widgets.Joystick.DualJoystickView;
import com.MobileAnarchy.Android.Widgets.Joystick.JoystickMovedListener;
import org.projectproto.btjoystick.DeviceListActivity;
import org.projectproto.btjoystick.BluetoothRfcommClient;
import org.projectproto.btjoystick.R.string;

import java.security.SecureRandom;
import java.util.List;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

import android.app.Activity;
import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.OnSharedPreferenceChangeListener;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorManager;
import android.hardware.SensorEventListener;
import android.location.GpsStatus.Listener;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class BluetoothJoystickActivity extends Activity implements
		OnSharedPreferenceChangeListener, SensorEventListener {

	// debug / logs
	private final boolean D = true;
	private static final String TAG = BluetoothJoystickActivity.class
			.getSimpleName();

	// Message types sent from the BluetoothRfcommClient Handler
	public static final int MESSAGE_STATE_CHANGE = 1;
	public static final int MESSAGE_READ = 2;
	public static final int MESSAGE_WRITE = 3;
	public static final int MESSAGE_DEVICE_NAME = 4;
	public static final int MESSAGE_TOAST = 5;

	// Key names received from the BluetoothRfcommClient Handler
	public static final String DEVICE_NAME = "device_name";
	public static final String TOAST = "toast";

	// Intent request codes
	private static final int REQUEST_CONNECT_DEVICE = 1;
	private static final int REQUEST_ENABLE_BT = 2;

	// Name of the connected device
	private String mConnectedDeviceName = null;
	// Local Bluetooth adapter
	private BluetoothAdapter mBluetoothAdapter = null;
	// Member object for the RFCOMM services
	private BluetoothRfcommClient mRfcommClient = null;

	// Layout View
	DualJoystickView mDualJoystick;
	private TextView mTxtStatus;
	private TextView mTxtDataCartesiana;
	private TextView mTxtDataSent;
	private TextView mTxtDataSentDebug;

	// polar coordinates
	private int mEjeYL = 0;
	private int mEjeXL = 0;
	private int accX_Leido, accY_Leido, accZ_Leido;
	private int accX_Transf, accY_Transf, accZ_Transf;
	private int MatrizX;

	private MenuItem mItemConnect;

	// timer task
	private Timer mUpdateTimer;
	private long mUpdatePeriod;

	public TextView X_Leido, Y_Leido, Z_Leido;
	public TextView X_Transf, Y_Transf, Z_Transf;

	private Button ResetMatrix;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.main);

		// Get local Bluetooth adapter
		mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

		// If the adapter is null, then Bluetooth is not supported
		if (mBluetoothAdapter == null) {
			Toast.makeText(this, "Bluetooth is not available",
					Toast.LENGTH_LONG).show();
			finish();
			return;
		}

		// If BT is not on, request that it be enabled.
		if (!mBluetoothAdapter.isEnabled()) {
			Intent enableIntent = new Intent(
					BluetoothAdapter.ACTION_REQUEST_ENABLE);
			startActivityForResult(enableIntent, REQUEST_ENABLE_BT);
		}

		// Initialize the BluetoothRfcommClient to perform bluetooth connections
		mRfcommClient = new BluetoothRfcommClient(this, mHandler);

		mDualJoystick = (DualJoystickView) findViewById(R.id.dualjoystickView);
		mDualJoystick.setOnJostickMovedListener(_listenerLeft);
		mDualJoystick.setYAxisInverted(true);
		mDualJoystick.setMovementRange((float) 255);

		mTxtStatus = (TextView) findViewById(R.id.txt_status);
		mTxtDataCartesiana = (TextView) findViewById(R.id.txt_dataCartesiana);
		mTxtDataSent = (TextView) findViewById(R.id.txt_dataSent);
		mTxtDataSentDebug = (TextView) findViewById(R.id.txt_dataSentDebug);

		MatrizX = 0;

		ResetMatrix = (Button) findViewById(R.id.ResetMatrix);

		X_Leido = (TextView) findViewById(R.id.xID_Leido);
		Y_Leido = (TextView) findViewById(R.id.yID_Leido);
		Z_Leido = (TextView) findViewById(R.id.zID_Leido);

		X_Transf = (TextView) findViewById(R.id.xID_transf);
		Y_Transf = (TextView) findViewById(R.id.yID_transf);
		Z_Transf = (TextView) findViewById(R.id.zID_transf);

		ResetMatrix.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				MatrizX = accX_Leido;

			}
		});

		// mUpdatePeriod = prefs.getLong( "updates_interval", 200 ); // in
		// milliseconds
		mUpdatePeriod = 50;

		// fix me: use Runnable class instead
		mUpdateTimer = new Timer();
		mUpdateTimer.schedule(new TimerTask() {
			public void run() {
				BluetoothJoystickActivity.this.runOnUiThread(new Runnable() {
					@Override
					public void run() {
						UpdateMethod();

					}
				});
			}
		}, 2000, mUpdatePeriod); // Dentro de 2000 msg empezara a ejecutar la
									// funcion cada 'mUpdatePeriod' msg

		SensorManager sm = (SensorManager) getSystemService(SENSOR_SERVICE);
		List<Sensor> AccSensors = sm.getSensorList(Sensor.TYPE_ACCELEROMETER);
		if (AccSensors.size() > 0) {
			sm.registerListener(this, AccSensors.get(0),
					SensorManager.SENSOR_DELAY_NORMAL);
		}

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		mItemConnect = menu.add("Connect");
		return (super.onCreateOptionsMenu(menu));

	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		if (item == mItemConnect) {
			Intent serverIntent = new Intent(this, DeviceListActivity.class);
			startActivityForResult(serverIntent, REQUEST_CONNECT_DEVICE);
		}
		return super.onOptionsItemSelected(item);
	}

	public void onSharedPreferenceChanged(SharedPreferences prefs, String key) {

	}

	@Override
	public synchronized void onResume() {
		super.onResume();
		if (mRfcommClient != null) {
			// Only if the state is STATE_NONE, do we know that we haven't
			// started already
			if (mRfcommClient.getState() == BluetoothRfcommClient.STATE_NONE) {
				// Start the Bluetooth RFCOMM services
				mRfcommClient.start();
			}
		}
	}

	@Override
	public void onDestroy() {
		mUpdateTimer.cancel();
		// Stop the Bluetooth RFCOMM services
		if (mRfcommClient != null)
			mRfcommClient.stop();
		super.onDestroy();
	}

	@Override
	public void onBackPressed() {
		new AlertDialog.Builder(this)
				.setTitle("Bluetooth Joystick")
				.setMessage("Close this controller?")
				.setPositiveButton("Yes",
						new DialogInterface.OnClickListener() {
							public void onClick(DialogInterface dialog,
									int which) {
								finish();
							}
						}).setNegativeButton("No", null).show();
	}

	private JoystickMovedListener _listenerLeft = new JoystickMovedListener() {

		public void OnMoved(int pan, int tilt) {
			mTxtDataCartesiana
					.setText(String.format("( %d, %d )", -pan, -tilt));
			mEjeXL = -pan;
			mEjeYL = -tilt;
		}

		public void OnReleased() {
			//
		}

		public void OnReturnedToCenter() {
			mEjeYL = mEjeXL = 0;
		}
	};

	/**
	 * Sends a message.
	 * 
	 * @param message
	 *            A string of text to send.
	 */
	private void sendMessage(String message) {
		// Check that we're actually connected before trying anything
		if (mRfcommClient.getState() != BluetoothRfcommClient.STATE_CONNECTED) {
			// return;
		}
		// Check that there's actually something to send
		if (message.length() > 0) {
			// Get the message bytes and tell the BluetoothRfcommClient to write
			byte[] send = message.getBytes();
			mRfcommClient.write(send);
		}
	}

	private void UpdateMethod() {

		String Cadena = new String();

		// 1- identificacion de signo de todos los valores
		int i_inicio = 0x5555;
		int i_fin = 0xFFFF;
		
		int canal1 = (mEjeXL + 255); // Entre 0 y 512
		int canal2 = (mEjeYL + 255); // Entre 0 y 512
		int canal3 = (accX_Leido + 255); // Entre 0 y 512
		int canal4 = (accX_Leido + 255); // Entre 0 y 512
		int canal5 = (accX_Leido + 255); // Entre 0 y 512
		int canal6 = 1; // Entre 0 y 1
		
		if(canal1 < 0) canal1 = 0;
		if(canal2 < 0) canal1 = 0;
		if(canal3 < 0) canal1 = 0;
		if(canal4 < 0) canal1 = 0;
		if(canal5 < 0) canal1 = 0;
		if(canal6 < 0) canal1 = 0;
		
		// Nuevo protocolo de envio de datos:
		// 5555 <Canal1> <Canal2> <Canal3> <Canal4> <Canal5> <Canal6> FFFF
		String strInicio = String.format("%04X", 0xFFFF & i_inicio);
		String strCanal1 = String.format("%04X", 0xFFFF & canal1);
		String strCanal2 = String.format("%04X", 0xFFFF & canal2);
		String strCanal3 = String.format("%04X", 0xFFFF & canal3);
		String strCanal4 = String.format("%04X", 0xFFFF & canal4);
		String strCanal5 = String.format("%04X", 0xFFFF & canal5);
		String strCanal6 = String.format("%04X", 0xFFFF & canal6);
		String strFin = String.format("%04X", 0xFFFF & i_fin);
		
		Cadena = strInicio + strCanal1 + strCanal2 + strCanal3 + strCanal4 + strCanal5 + strCanal6 + strFin;
		
		String CadenaDebug = strInicio + "-" + strCanal1 + "-" + strCanal2 + "-" + strCanal3 + "-" + strCanal4 + "-" + strCanal5 + "-" + strCanal6 + "-" + strFin;

		sendMessage(Cadena);

		this.X_Leido.setText("X = " + accX_Leido);
		this.Y_Leido.setText("Y = " + accY_Leido);
		this.Z_Leido.setText("Z = " + accZ_Leido);

		this.mTxtDataSent.setText(Cadena);
		this.mTxtDataSentDebug.setText(CadenaDebug);
		

	}

	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		switch (requestCode) {
		case REQUEST_CONNECT_DEVICE:
			// When DeviceListActivity returns with a device to connect
			if (resultCode == Activity.RESULT_OK) {
				// Get the device MAC address
				String address = data.getExtras().getString(
						DeviceListActivity.EXTRA_DEVICE_ADDRESS);
				// Get the BLuetoothDevice object
				BluetoothDevice device = mBluetoothAdapter
						.getRemoteDevice(address);
				// Attempt to connect to the device
				mRfcommClient.connect(device);
			}
			break;
		case REQUEST_ENABLE_BT:
			// When the request to enable Bluetooth returns
			if (resultCode != Activity.RESULT_OK) {
				// User did not enable Bluetooth or an error occurred
				Toast.makeText(this, R.string.bt_not_enabled_leaving,
						Toast.LENGTH_SHORT).show();
				finish();
			}
			break;
		}
	}

	// The Handler that gets information back from the BluetoothRfcommClient
	private final Handler mHandler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case MESSAGE_STATE_CHANGE:
				switch (msg.arg1) {
				case BluetoothRfcommClient.STATE_CONNECTED:
					mTxtStatus.setText(R.string.title_connected_to);
					mTxtStatus.append(" " + mConnectedDeviceName);
					break;
				case BluetoothRfcommClient.STATE_CONNECTING:
					mTxtStatus.setText(R.string.title_connecting);
					break;
				case BluetoothRfcommClient.STATE_NONE:
					mTxtStatus.setText(R.string.title_not_connected);
					break;
				}
				break;
			case MESSAGE_READ:
				// byte[] readBuf = (byte[]) msg.obj;
				// int data_length = msg.arg1;
				break;
			case MESSAGE_DEVICE_NAME:
				// save the connected device's name
				mConnectedDeviceName = msg.getData().getString(DEVICE_NAME);
				Toast.makeText(getApplicationContext(),
						"Connected to " + mConnectedDeviceName,
						Toast.LENGTH_SHORT).show();
				break;
			case MESSAGE_TOAST:
				Toast.makeText(getApplicationContext(),
						msg.getData().getString(TOAST), Toast.LENGTH_SHORT)
						.show();
				break;
			}
		}
	};

	public void onAccuracyChanged(Sensor sensor, int accuracy) {
	}

	public void onSensorChanged(SensorEvent event) {
		switch (event.sensor.getType()) {
		case Sensor.TYPE_ACCELEROMETER:
			accX_Leido = (int) ((event.values[SensorManager.DATA_X] * 255) / 9.8);
			accY_Leido = (int) ((event.values[SensorManager.DATA_Y] * 255) / 9.8);
			accZ_Leido = (int) ((event.values[SensorManager.DATA_Z] * 255) / 9.8);

			if (accX_Leido > 255)
				accX_Leido = 255;
			if (accY_Leido > 255)
				accY_Leido = 255;
			if (accZ_Leido > 255)
				accZ_Leido = 255;

			if (accZ_Leido >= 0)// El movil esta en vertical
			{
				accX_Transf = accX_Leido - MatrizX;
			} else {
				accX_Transf = 255 + (255 - accX_Leido) - MatrizX;
			}
			if (accX_Transf >= 256)
				accX_Transf = 255;

			accY_Transf = accY_Leido;
			accZ_Transf = accZ_Leido;

			break;
		}

	}
}
