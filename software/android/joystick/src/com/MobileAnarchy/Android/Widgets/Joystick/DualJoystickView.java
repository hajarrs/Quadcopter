package com.MobileAnarchy.Android.Widgets.Joystick;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.LinearLayout;

public class DualJoystickView extends LinearLayout 
{
	@SuppressWarnings("unused")
	private static final String TAG = DualJoystickView.class.getSimpleName();
	
	private final boolean D = false;
	private Paint dbgPaint1;

	private JoystickView stickL;

	public DualJoystickView(Context context) 
	{
		super(context);
		stickL = new JoystickView(context);
		initDualJoystickView();
	}

	public DualJoystickView(Context context, AttributeSet attrs) 
	{
		super(context, attrs);
		stickL = new JoystickView(context, attrs);
		initDualJoystickView();
	}

	private void initDualJoystickView() 
	{
		setOrientation(LinearLayout.HORIZONTAL);
		setMovementRange((byte)255);
		
		// joystick Izquierda
		stickL.setHandleColor(Color.rgb(0x70, 0x20, 0x20));		
	}
	
	@Override
	protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
		super.onMeasure(widthMeasureSpec, heightMeasureSpec);
		removeView(stickL);

		float padW = getMeasuredWidth()-(getMeasuredHeight()*2);
		int joyWidth = (int) ((getMeasuredWidth()-padW)/2);
		
		LayoutParams joyLParams = new LayoutParams(joyWidth,getMeasuredHeight());
		stickL.setLayoutParams(joyLParams);
		stickL.TAG = "L";
		stickL.setPointerId(JoystickView.INVALID_POINTER_ID);
		addView(stickL);
	}
	
	@Override
	protected void onLayout(boolean changed, int l, int t, int r, int b) {
		super.onLayout(changed, l, t, r, b);
	}
	
	public void setAutoReturnToCenter(boolean left) {
		stickL.setAutoReturnToCenter(left);
	}
	
	public void setOnJostickMovedListener(JoystickMovedListener left) {
		stickL.setOnJostickMovedListener(left);
	}
	
	public void setOnJostickClickedListener(JoystickClickedListener left) {
		stickL.setOnJostickClickedListener(left);
	}
	
	public void setYAxisInverted(boolean leftYAxisInverted) {
		stickL.setYAxisInverted(leftYAxisInverted);
	}

	public void setMovementConstraint(int movementConstraint) {
		stickL.setMovementConstraint(movementConstraint);
	}
	
	public void setMovementRange(float movementRangeLeft ) {
		stickL.setMovementRange(movementRangeLeft);
	}
	
	public float getMovementRange() 
	{
		return stickL.getMovementRange();
	}
	
	public void setMoveResolution(float leftMoveResolution) {
		stickL.setMoveResolution(leftMoveResolution);
	}

	public void setUserCoordinateSystem(int leftCoordinateSystem ) {
		stickL.setUserCoordinateSystem(leftCoordinateSystem);
	}
	
	@Override
	protected void dispatchDraw(Canvas canvas) {
		super.dispatchDraw(canvas);
		if (D) {
			canvas.drawRect(1, 1, getMeasuredWidth()-1, getMeasuredHeight()-1, dbgPaint1);
		}
	}
	@Override
	public boolean dispatchTouchEvent(MotionEvent ev) {
    	boolean l = stickL.dispatchTouchEvent(ev);
    	return l;
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent ev) {
    	boolean l = stickL.onTouchEvent(ev);
    	return l;
	}
}
