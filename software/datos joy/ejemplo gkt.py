# -*- coding:Utf-8 -*-
import pygtk
pygtk.require("2.0")
import gtk
import cairo

class espaceDessin(gtk.DrawingArea):
 def __init__(self):
 	super(espaceDessin, self).__init__()

 	self.set_size_request(400, 400)
 	self.modify_bg(gtk.STATE_NORMAL, gtk.gdk.color_parse("white"))
 	self.add_events(gtk.gdk.BUTTON_PRESS_MASK | gtk.gdk.BUTTON_RELEASE_MASK | gtk.gdk.BUTTON1_MOTION_MASK)
 	self.connect("button-press-event", self.boutonSourisEnfonce)
 	self.connect("motion-notify-event", self.sourisBouge)
 	self.connect("button-release-event", self.boutonSourisRelache)
 	self.connect("expose-event", self.expose)

 	self.surface1 = cairo.ImageSurface.create_from_png("ball.png")
 	self.surface2 = cairo.ImageSurface.create_from_png("ball.png")
 	self.surface3 = cairo.ImageSurface.create_from_png("ball.png")

 	self.largeur1 = self.surface1.get_width()
 	self.hauteur1 = self.surface1.get_height()
 	self.largeur2 = self.surface2.get_width()
 	self.hauteur2 = self.surface2.get_height()
 	self.largeur3 = self.surface3.get_width()
 	self.hauteur3 = self.surface3.get_height()

 	self.posX1 = 0
 	self.posY1 = 0
 	self.posX2 = 150
 	self.posY2 = 200
 	self.posX3 = 250
 	self.posY3 = 100

 	self.imageSelectionne = ''

 	self.posSourisX = -1
 	self.posSourisY = -1

 def boutonSourisEnfonce(self, widget, evenement):
 	if evenement.button == 1:
 		if evenement.x > self.posX1 and evenement.x < self.posX1 + self.largeur1:
 			if evenement.y > self.posY1 and evenement.y < self.posY1 + self.hauteur1:
 				self.imageSelectionne = 'GTK'
 		elif evenement.x > self.posX2 and evenement.x < self.posX2 + self.largeur2:
 			if evenement.y > self.posY2 and evenement.y < self.posY2 + self.hauteur2:
 				self.imageSelectionne = 'TUX'
 		elif evenement.x > self.posX3 and evenement.x < self.posX3 + self.largeur3:
 			if evenement.y > self.posY3 and evenement.y < self.posY3 + self.hauteur3:
 				self.imageSelectionne = 'BABYTUX'
 		else:
 			self.imageSelectionne = ''

 def sourisBouge(self, widget, evenement):
 	if evenement.is_hint:
 		self.posSourisX, self.posSourisY, state = event.window.get_pointer()
 	else:
 		self.posSourisX = evenement.x
 		self.posSourisY = evenement.y
 		state = evenement.state
 	if state & gtk.gdk.BUTTON1_MASK:
 		contexte = self.window.cairo_create()
 		contexte.set_source_rgb(255, 255, 255)
 		contexte.paint()
 		if self.imageSelectionne == 'GTK':
 			contexte.set_source_surface(self.surface1, self.posX1, self.posY1)
 			contexte.paint()
 			self.posX1 = self.posSourisX - self.largeur1 / 2
 			self.posY1 = self.posSourisY - self.hauteur1 / 2
 		elif self.imageSelectionne == 'TUX':
 			contexte.set_source_surface(self.surface2, self.posX2, self.posY2)
 			contexte.paint()
 			self.posX2 = self.posSourisX - self.largeur2 / 2
 			self.posY2 = self.posSourisY - self.hauteur2 / 2
 		elif self.imageSelectionne == 'BABYTUX':
 			contexte.set_source_surface(self.surface3, self.posX3, self.posY3)
 			contexte.paint()
 			self.posX3 = self.posSourisX - self.largeur3 / 2
 			self.posY3 = self.posSourisY - self.hauteur3 / 2
 		self.expose(widget, None)

 def boutonSourisRelache(self, widget, evenement):
 	self.expose(widget, None)

 def expose(self, widget, evenement):
 	contexte = widget.window.cairo_create()
 	contexte.set_source_rgb(255, 255, 255)
 	contexte.set_source_surface(self.surface1, self.posX1, self.posY1)
 	contexte.paint()
 	contexte.set_source_surface(self.surface2, self.posX2, self.posY2)
 	contexte.paint()
 	contexte.set_source_surface(self.surface3, self.posX3, self.posY3)
 	contexte.paint()

class PyGtkApp(gtk.Window):
 def __init__(self):
 	super(PyGtkApp, self).__init__()

 	self.set_title("Drag and Drop dans DrawingArea")
 	self.set_default_size(640, 480)
 	self.set_position(gtk.WIN_POS_CENTER)

 	zoneDessin = espaceDessin()
 	boiteH = gtk.HBox()
 	boiteV = gtk.VBox()
 	boiteH.pack_start(boiteV, False, False)
 	boiteV.pack_start(zoneDessin, False, False)
 	self.add(boiteH)

 	self.connect("destroy", gtk.main_quit)

 	self.show_all()

PyGtkApp()
gtk.main()