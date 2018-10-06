void fun(){
ofSetFullscreen(true);
ofBackground(0,0,255);
    ofSetColor(255,255,255);
    string msg = "A problem has been detected and Windows has been shut down to prevent damage";
        msg += "\nto your computer.";

        msg += "\n\nThe problem seems to be caused by the following file: WIN32.SYS";

        msg += "\n\nPAGE_FAULT_IN_NONPAGED_AREA";

        msg += "\n\nIf this is the first time you've seen this stop error screen,";
        msg += "\nrestart your computer. If this screen appears again, follow these";
        msg += "\nsteps:";

        msg += "\n\nCheck to make sure any new hardware or software is properly installed.";
        msg += "\nIf this is a new installation, ask your hardware or software manufacturer";
        msg += "\nfor any Windows updates you might need.";

        msg += "\n\nIf problems continue, disable or remove any newly installed hardware";
        msg += "\nor software. Disable BIOS memory options such as caching or shadowing.";
        msg += "\nDelete System32 and reinstall Windows. If you need to use Safe Mode to";
        msg += "\nremove or disable components, restart your computer, press F8 to select";
        msg += "\nAdvanced Startup Options, and then select Safe Mode.";

        msg += "\n\nTechnical information:";

        msg += "\n\n*** STOP: 0x00000050 (0xFD3094C2,0x00000001,0xFBFE7617,0x00000000)";

        msg += "\n\n*** WIN32.SYS - Address FBFE7617 base at FBFE5000, DateStamp 1d3dd37c";
    ofDrawBitmapString(msg,ofGetWindowWidth()/4,ofGetWindowHeight()/4);
}