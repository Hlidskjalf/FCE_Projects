#include <iostream>
#include <windows.h>
#include <sstream>

int terminate_MWS_Store();
int clean_up();
int main_menu();
int terminate_custom();
int update_stores();

std::string store;

int main(int argc, char **argv)
{
  std::cout << "***************************************\n"
	    << "*Basic Back Office Maintenance Program*\n"
	    << "*           Version 1.1               *\n"
	    << "* An in-progress endeavor to create a *\n"
	    << "* robust utility program for the FCE  *\n"
	    << "*            helpdesk.                *\n"
	    << "***************************************\n";
  std::cout << "Enter the store number: ";
  std::cin >> store;
  main_menu();
  return 0;
}

int main_menu()
{
  std::cout << "Current Store Number: FCE-" << store << ".\n";
  std::cout << "Please choose from the following options: \n"
	    << "\t1) Terminate MWS Store.\n"
	    << "\t2) Run clean_up.bat.\n"
	    << "\t3) Terminate custom process.\n"
	    << "\t4) Enter new Store number.\n"
	    << "\t5) Update Stores (beta).\n"
	    << "\t6) Exit.\n";
  int choice;
  std::cin >> choice;
  switch(choice)
      {
      case 1:
	terminate_MWS_Store();
	main_menu();
	break;

      case 2:
	std::cout << "Execution of this script requires that it has been \n"
		  << "placed into the C:\\Install directory on the store \n"
		  << "PC. Please ensure that has been completed before \n"
		  << "continuing. Would you like to continue? (y/n) \n";
	    clean_up();
	    main_menu();
	    break;
	
      case 3:
	terminate_custom();
	main_menu();
	break;

      case 4:
        std::cout << "Enter the store number: ";
	std::cin >> store;
	main_menu();
	break;

      case 5:
	std::cout << "Please ensure that the correct parameters in the \n"
		  << "script have been set. This application does not \n"
		  << "have the capability to edit the script's parameters. \n"
		  << "Would you like to execute the script as is? (y/n)";
	update_stores();
	main_menu();
	break;

      case 6:
	std::cout << "Exiting...";
	break;
    }
  return 0;
}

int terminate_MWS_Store()
{
  std::string cmd("psexec \\\\fce-");
  cmd += store;
  cmd += " -u helpdesk -p LimeCoke taskkill /f /im MWSStore.exe";
  
  system(cmd.c_str());

  return 0;
}

int terminate_custom()
{
  std::string process;
  std::cout << "Enter the process as it would appear in Task Manager: ";
  std::cin >> process;
  std::string cmd("psexec \\\\fce-");
  cmd += store;
  cmd += " -u helpdesk -p LimeCoke taskkill /f /im ";
  ;  cmd += process;

  system(cmd.c_str());

  return 0;
}

int clean_up()
{
  std::string cont;
  std::cin >> cont;
  if(cont == "y" || cont == "Y")
    {
      std::string cmd("psexec \\\\fce-");
      cmd += store;
      cmd += " -u helpdesk -p LimeCoke C:\\Install\\clean_up.bat";
  
      system(cmd.c_str());
    }

  return 0;
}

int update_stores()
{
  std::string execute;
  std::cin >> execute;
  if (execute == "y" || execute == "Y")
    {
      system("C:\\Users\\avroman\\Documents\\Useful\\Prog\\cpp\\MWS_Store_Fixes\\PSKill\\tcc.btm");
    }
  else if (execute == "n" || execute == "N")
    {
      //TODO: launch an editor and the script for editing
      return 0;
    }
    
  return 0;
}
