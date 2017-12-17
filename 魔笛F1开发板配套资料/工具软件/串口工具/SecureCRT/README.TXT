
             SecureCRT(R) 5.5 (Official) -- April 5, 2007

            Copyright (C) 1995-2007 VanDyke Software, Inc.
                        All rights reserved.


Product Overview
----------------

SecureCRT protects your passwords, user accounts, and data, combining
rock-solid terminal emulation with the strong encryption, broad
authentication options, and data integrity of the Secure Shell (SSH)
protocol.

SecureCRT provides versatile solutions for a wide range of business,
network management, information security, and development tasks, from
accessing host-based applications and administering servers to
securely accessing behind-the-firewall network resources like e-mail,
files, and printers.

SecureCRT supports SSH1, SSH2, Telnet, Telnet/SSL, RLogin, Serial,
and TAPI protocols and authentication via password, public key, X.509
certificate, and Kerberos v5 via GSSAPI.  Ciphers include AES,
Twofish, Blowfish, 3DES, and RC4.

Choose from a wide range of emulations including VT100, VT102, VT220,
ANSI, SCO ANSI, Wyse 50/60, Xterm, and Linux console -– all with ANSI
color.  Multibyte character sets are supported for Japanese, Korean,
and Chinese, as is support for scalable line-drawing fonts.

SecureCRT features a multi-session tabbed interface with extensive
session management and customization features.  Customization options
include toolbars, menus, keymaps, and login scripts, as well as fonts,
cursors, and color schemes. 

Named sessions and firewalls let you create individual configurations
that can be used on a session-specific basis.  Other features include
the Activator tray utility to minimize desktop clutter, auto logon,
printing, Emacs mode, and SOCKS firewall support.

Powerful scripting capabilities, including ActiveX scripting support
for VBScript and other scripting languages, save you valuable time by
automating routine configuration tasks.  Secure file transfers can be
performed using Zmodem or Xmodem from an SSH1 or SSH2 session. 

SecureCRT and the SecureFX(R) file transfer client can be integrated,
letting you share global and session options and the host key database
so configuring a server connection only needs to be done once.

SecureCRT includes a 30-day try-before-you-buy evaluation license for
the fully functional application and access to VanDyke Software(R)
technical support.



Contents
--------

   1. New for SecureCRT 5.5
   2. Enhancement Requests, Updates, and Questions
   3. Encryption Export
   4. Upgrades
   5. Product History
   6. Secure Shell Server Notes
   7. SecureCRT Features
   8. Reporting Bugs
   9. Contact Information


1. New For SecureCRT 5.5
------------------------

The major new features for SecureCRT 5.5 are:

  New productivity enhancements.

    Script recorder: Quickly create a script to automate routines
    using the new script recorder, which records keystrokes including
    function keys, and then generates a VB script.

    Improved auto session: With "Use auto session" enabled, you can
    now select a single session, multiple sessions, or folders of
    sessions to automatically connect on startup.

    Cache passwords: SSH2 session passwords can be cached like
    passphrases.  SecureCRT and SecureFX can share passwords while
    either application or the Activator utility is running.

  Improved ANSI color with color schemes.
    When using ANSI color, you can now select a color scheme to
    replace the standard white foreground and black background.

  Expanded logging options with custom log data.
    Custom log data gives you the ability to specify strings to be
    logged upon connect, disconnect, and on each line.  Parameter
    substitutions for session and date information are supported.

  Support for OpenSSH format keys.
    You can now generate keys in OpenSSH format or convert existing
    VanDyke Software format private keys to OpenSSH format, allowing
    you to use the same keys with other Secure Shell clients.

  Support for zlib@openssh.com compression.
    When zlib@openssh.com compression is specified, compression starts
    after authentication, preventing unencrypted passwords from being
    cached by the zlib library.

  Additional tab support.
    Display the list of tabs on the menu using the MENU_TAB_LIST1
    custom menu item. A new script function, GetScriptTab, returns the
    tab from which the script was started.

  Windows Vista support.
    SecureCRT has been tested under Windows Vista, so when you are
    ready to move to Vista, SecureCRT will be compatible.


2. Enhancement Requests, Updates, and Questions
-----------------------------------------------

We want to hear from you.  Let us know what features you would like to
see in future releases of SecureCRT by visiting our web site at:

  http://www.vandyke.com/feedback.php

Every VanDyke Software license includes a full year of upgrades and
technical support.  To receive e-mail notification when new releases
of SecureCRT are available, sign up for our SecureCRT mailing list at:

  https://secure.vandyke.com/cgi-bin/subscribe.php?RMF=3

For tips, ideas, and product news, subscribe to VanDyke Software's
monthly newsletter at:

  https://secure.vandyke.com/cgi-bin/subscribe.php?RMF=3

You can also exchange useful tips and ideas with your peers and
VanDyke developers by joining the online forums:

  http://forums.vandyke.com/index.php?RMF=3

If you have any questions, please visit our web site at:

  http://www.vandyke.com/feedback.php


By default, SecureCRT 5.5 stores all settings and sessions in:

  "C:\Documents and Settings\<Username>\Application Data
    \VanDyke\Config"

If a version of SecureCRT older than 5.0 was installed, your settings
and sessions will need to be migrated, which will move them to a new
location.  If migration is necessary, you will be prompted for the
new location the first time you run SecureCRT 5.5.

SecureCRT supports Windows Vista 2003, XP, and 2000.


3. Encryption Export
--------------------

This Software is subject to export control.  The Software may be
transmitted, exported, or re-exported only under applicable export
laws and restrictions and regulations of the United States Bureau of
Industry and Security or foreign agencies or authorities.  By
downloading or using the Software, you are agreeing to comply with
export controls.  For more information see:

  http://www.vandyke.com/download/export.html


4. Upgrades
-----------

Users who purchased SecureCRT on or after March 1, 2006, are eligible
for a free upgrade to SecureCRT 5.5.  All users can evaluate SecureCRT
5.5 for 30 days free of charge.  For more information on upgrade
eligibility and purchasing upgrades, please visit:

  http://www.vandyke.com/pricing/corporate/upgrades


5. Product History
------------------

The list of changes made for this release of SecureCRT can be found in
the History.txt file installed with the program.


6. Secure Shell Server Notes
----------------------------

Public-key assistant requires server-side support (e.g., VShell(R) 2.1
or newer).

Public-key authentication using SmartCards and X.509 requires SSH
Communications 3.0.1 (or newer) server.

Password, public-key, and keyboard-interactive authentications are
supported.

Public-key authentication requires one of the following Secure Shell
servers:

  VShell 1.0 (or newer)
  SSH Communications 2.0.13, 2.1 (or newer)
  F-Secure 2.0.13 (or newer)
  OpenSSH 2.1.1 (or newer)

VShell for Windows NT/XP/2000/2003 and UNIX/Linux are available from:

  www.vandyke.com

OpenSSH is available by FTP and HTTP download from:

  www.openssh.com


7. SecureCRT Features 
---------------------

Support for SSH1 and SSH2 Secure Shell protocols.
  - SSH2 Protocol support:
    - AES-128, AES-192, AES-256, Twofish, Blowfish, 3DES, and RC4
      ciphers.
    - RSA and DSA host key support.
    - Multiple ordered authentication methods, ciphers and MACs.
    - Public Key Assistant makes it easier to upload public keys.
    - Local port forwarding, X11 forwarding, remote forwarding, and
      dynamic forwarding.
    - MD5, MD5-96, SHA1, and SHA1-96 MACs.
    - RSA, DSA, public-key, X.509 certificate, Kerberos v5 via GSSAPI,
      and password authentication methods.
    - SFTP tab creates an SFTP session to an existing SSH session.
  - SSH1 Protocol support:
    - Blowfish, DES, 3DES, and RC4 ciphers.
    - RSA, TIS, and password authentication.
    - Local port forwarding, X11 forwarding.

Session Management.
  - Named sessions store different preferences for different hosts.
  - Tabbed sessions allow multiple sessions in the same window.
  - Launch multiple selected sessions in tabs with a single click.
  - Option to minimize SecureCRT windows to the Activator utility in
    the system tray.
  - The Activator utility acts as an SSH agent.
  - A session can be logged to a file, including options for logging
    custom data.

Configuration & Customization.
  - Easy configuration of basic SSH, port forwarding, remote
    forwarding and other settings in Session Options dialog.
  - Named firewalls.
  - Customizable toolbar and menus.
  - User-defined number of savelines (scrollback) up to 32,000.
  - User-configurable number of rows and columns.
  - User-defined foreground, background, and bold colors.
  - User-defined keymaps.
  - User-defined word delimiter characters for double-click.
  - Emacs mode maps ALT+<key> to send ESC+<key>.

Advanced Terminal Emulation.
  - Quality VT100, VT102, VT220, Linux console, SCO ANSI, Wyse 50/60
    and ANSI emulation:
    - VT line drawing.
    - Support for bold, underline, and reverse attributes.
    - Double-width and double-height fonts.
    - 80/132 column switching.
    - VT100 and VT220 keyboard emulation.
    - Optional ANSI color.
    - 256-color Xterm.
    - Xterm extensions for mouse support and changing title bar.
    - Multi-byte character set support for Japanese, Korean, and
      Chinese.
 
Other Features.
  - FIPS 140-2 validated cryptographic library support.
  - Variable compression increases performance on slow connections.
  - Simple interface for automating logins.
  - Support for Telnet, Telnet/SSL, and RLogin protocols:
    - Telnet supports Negotiate About Window Size (NAWS).
    - Telnet supports Local Flow Control (LFLOW).
  - Serial (COM) device support.
  - Integration with SecureFX 3.x or higher.
  - Scripting language support for VBScript and JScript.
  - Script recorder.
  - Zmodem and Xmodem file transfer (upload and download).
  - Printing: auto print, selection, screen, and pass-through 
    printing.
  - Modem dialer support: configure and save modem, country code,
    phone, and redial settings for TAPI sessions.
  - SOCKS firewall support with password authentication.
  - Unauthenticated and basic HTTP proxy support.
  - Generic proxy firewall support.
  - Copy and paste, including an "auto copy" option and a "paste on
    middle or right mouse click" option.
  - Chat window option provides an editable type-ahead buffer with
    history support.
  - Support for use from the command line or web browsers.
  - Support for standard insertion caret so that it can be tracked
    by screen access technology for the blind.


8. Reporting Bugs
-----------------

If you experience an uncaught exception, General Protection Fault
(GPF), or something you believe is a bug, please fill out our online
form at:

  http://www.vandyke.com/feedback.php

Please do not assume someone else will report it.  We will try to
resolve reported bugs as quickly as possible.  However, we can't
resolve bugs that are not reported.

Please describe the problem in as much detail as possible. Please
include the following information:

  - Version of SecureCRT (as shown in the About dialog)
  - Operating system and version


9. Contact Information
-----------------------

For information on ordering licenses, please visit the VanDyke
Software web site:

  http://www.vandyke.com


All other inquiries should be directed to:

  VanDyke Software, Inc.
  4848 Tramway Ridge Dr. NE
  Suite 101
  Albuquerque, NM 87111
  USA

  Inquiry form: http://www.vandyke.com/feedback.php


VanDyke Software, SecureCRT, SecureFX, and VShell are trademarks or 
registered trademarks of VanDyke Software, Inc. in the United States 
and/or other countries.

All other products and services mentioned are trademarks or registered
trademarks of their respective companies.