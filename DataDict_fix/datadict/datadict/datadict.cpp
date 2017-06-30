#include <iostream>
#include <fstream>
#include <windows.h>

/**
* This program was designed with the intention of removing file corruption
* and replacing the group of files involved with the corruption with a set
* from backup. Error checking begins with the C:\ drive, and moves onto the
* E:\ drive if that directory is not found. Execution is set in a top down
* fashion to ensure there is never more than a single copy of the DATADICT
* files in use.
*  Version - 0.1.0 - Checks for the .$$$ files on the C:\ drive
*                    Deletes the .$$$ file and copies the DATADICT group
*                    from C:\Install\DATADICT_REPO if the .$$$ file exists.
*                    If the file is not found, the same process is run on
*                    the E:\ to account for SD Card configurations.
*                    Prompts the user with a dialog box if the copy function
*                    fails.
*/

// Prototypes to deal with the compiler
void datadict_fix_C();
void datadict_fix_E();
int error_msg();

int main(int argc, char **argv)
{
	datadict_fix_C();
	datadict_fix_E();
	return 0;
}

/**
* Checks to see if DATADICT.$$$ exists and deletes it, while using that as
* the parameter to complete the rest of the function. If the deletion was
* successful then delete the rest of the DATADICT block and copy from a
* backup location. datadict_fix_C is limited to running processes on
* C:\Program Files\Pinnacle\Oaswin. Prompts the user if the copy fails.
*/

void datadict_fix_C()
{
	if (remove("C:\\Program Files\\Pinnacle\\Oaswin\\DATADICT.$$$") == 0) {

		// If the DATADICT.$$$ file existed on E:\Pinnacle\Oaswin, delete the block
		system("del /F /Q /Y \"C:\\Program Files\\Pinnacle\\Oaswin\\DATADICT.*\"");

		// Then copy the files from C:\Install\DATADICT_REPO
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.DBF",
			"C:\\Program Files\\Pinnacle\\Oaswin\\DATADICT.DBF", TRUE) == 0) {
			error_msg();
			return;
		}
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.CDX",
			"C:\\Program Files\\Pinnacle\\Oaswin\\DATADICT.CDX", TRUE) == 0) {
			error_msg();
			return;
		}
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.FPT",
			"C:\\Program Files\\Pinnacle\\Oaswin\\DATADICT.FPT", TRUE) == 0) {
			error_msg();
			return;
		}
	}
}

/**
* Checks to see if DATADICT.$$$ exists and deletes it, while using that as
* the parameter to complete the rest of the function. If the deletion was
* successful then delete the rest of the DATADICT block and copy from a
* backup location. datadict_fix_C is limited to running processes on
* E:\Pinnacle\Oaswin. Prompts the user if the copy fails.
*/

void datadict_fix_E()
{
	if (remove("E:\\Pinnacle\\Oaswin\\PL\\DATADICT.$$$") == 0) {

		// If the DATADICT.$$$ file existed on E:\Pinnacle\Oaswin, delete the block
		system("del /F /Q /Y E:\\Pinnacle\\Oaswin\\PL\\DATADICT.*");

		// Then copy the files from C:\Install\DATADICT_REPO
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.DBF",
			"E:\\Pinnacle\\Oaswin\\PL\\DATADICT.DBF", TRUE) == 0) {
			error_msg();
			return;
		}
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.CDX",
			"E:\\Pinnacle\\Oaswin\\PL\\DATADICT.CDX", TRUE) == 0) {
			error_msg();
			return;
		}
		if (CopyFile("C:\\Install\\DATADICT_REPO\\DATADICT.FPT",
			"E:\\Pinnacle\\Oaswin\\PL\\DATADICT.FPT", TRUE) == 0) {
			error_msg();
			return;
		}
	}
}


int error_msg()
{
	int error = MessageBox(
		NULL,
		"The DATADICT update has failed.\nPlease contact the HelpDesk\nfor assistance.",
		"Error",
		MB_OK | MB_ICONSTOP | MB_TOPMOST
	);
	return error;
}
