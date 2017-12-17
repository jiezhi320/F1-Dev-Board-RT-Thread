// Hello!  Welcome to the UltraEdit scripting environment.  Normally, you would
// put a header comment at the top of a javascript file to be used in UltraEdit
// in order to indicate the version of the UltraEdit scripting API, like so:
// Version = 1.00
// However, this is currently not necessary since the API will default to 1.00.

// ----------------------------------------------------------------------------
// stringvar.js
// This script queries the user for a string which will be used in a find 
// operation and a value that determines how many times the operation should
// occur.  A new file will be created for the results.  For each word found,
// the entire line will be selected, copied, and written to the result file.
// Copyright (c)2007 IDM Computer Solutions, Inc.
// ----------------------------------------------------------------------------
// UltraEdit is our application object.  All UltraEdit operations will use this
// object.
// See UltraEdit Help for more details.

// Get user input.
var num = UltraEdit.getValue("How many occurrences do you want to find?",1);
var str = UltraEdit.getString("What string do you want to find?",1);

// Create new file.  This will also become the active file.
UltraEdit.newFile();

UltraEdit.document[0].top();
// Do operation number of requested iterations.
var x = 0;
while (x < num) {
  UltraEdit.document[0].findReplace.find(str);
  UltraEdit.document[0].selectLine();
  UltraEdit.document[0].copy();
  if (UltraEdit.document[0].isFound() == true) {
    UltraEdit.activeDocument.paste();
  }
  x++;
}
