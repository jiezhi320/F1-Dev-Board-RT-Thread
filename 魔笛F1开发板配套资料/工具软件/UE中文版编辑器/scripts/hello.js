// Hello!  Welcome to the UltraEdit scripting environment.  Normally, you would
// put a header comment at the top of a javascript file to be used in UltraEdit
// in order to indicate the version of the UltraEdit scripting API, like so:
// Version = 1.00
// However, this is currently not necessary since the API will default to 1.00.

// ----------------------------------------------------------------------------
// hello.js
// A basic javascript to introduce our users to embedded scripting support in
// UltraEdit v13.00!
// Copyright (c)2007 IDM Computer Solutions, Inc.
// ----------------------------------------------------------------------------
// UltraEdit is our application object.  All UltraEdit operations will use this
// object.
// Operations may be performed on the activeDocument property of the UltraEdit
// object.
// See UltraEdit Help for more details.

//Create a new file, which will become the currently active document
UltraEdit.newFile();
//write the string "Hello World" to the currently active document
UltraEdit.activeDocument.write("Hello World!");
