***************************************************************
 Please read for information about the programs and .dbf files 
 in this directory. The .dbf files in DBF_Repo CANNOT be used  
                       at a store.                             
***************************************************************

The .dbf files contained in DBF_Repo cannot be used in any store
environment using programs made by the Pinnacle corp. The .dbf
files that are in use at the stores are in most ways identical,
but these files have been opened in a standard .dbf/.xls editor
and therefore have a flag that makes them unreadable in MWS Store.
These files are for editing and research ONLY.


**********************************************
reset_mws.exe Version - 0.0.3 - Commander POS 
**********************************************

This program enters and clears the C:\Naxml\Reports\ directory,
deletes any PL*.zip files that may be contained in the
C:\Program Files\Pinnacle\Oaswin directory, and removes all .xml
files from C:\Program Files\Pinnacle\Oaswin\POSExport\New\ on
the Commander POS back office PC. Added the capability to delete
from the E:\ drive as well, to eliminate failures from SD card
configuration. It uses a system call from windows.h to delete every
file in the directory without prompting the user for interaction.

To use this program effectively place the .exe in the Apps folder
of Oaswin, and use the PROCDICT.DBF & .CDX files in place of the
existing files on the store PC. The PROCDICT has the needed entries
to allow reset_mws.exe to be called at the beginning of Poll
Register Day.


***********************************************
datadict.exe Version - 0.1.0 - POS Independent
***********************************************

This program uses two similar functions to account for the
different SD Card configurations present. The first step checks
in C:\Program Files\Pinnacle\Oaswin for a file that has been
corrupted and renamed DATADICT.$$$. If found it is deleted, then
the block of DATADICT files are also deleted, and finally the
required files are replaced from a backup directory. If the
DATADICT.$$$ file is not found, no action is taken on the C:\
drive, and the program moves on to complete the same action on
E:\Pinnacle\Oaswin. Again, if the file is not found then no action
is taken. A top-down execution style prevents the possibility of there
being more than one set of the files in the \Oaswin directory at a
time.

This is designed to be a stand alone executable, with two means of
running the program: from the desktop, or on system boot by being
placed in the manager profile's Startup folder. To be successful
the DATADICT_REPO folder needs to be available in C:\Install. 

Added a dialog box to prompt the user to open a helpdesk ticket
should the copying process fail in any way.
