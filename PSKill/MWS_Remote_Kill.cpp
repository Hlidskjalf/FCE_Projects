#include <iostream>
#include <windows.h>
#include <sstream>

int terminate_MWS_Store();
int clean_up();

int main(int argc, char **argv)
{
  char user_input;
  std::cout << "Would you like to run clean_up.bat?";
  std::cin >> user_input;
  if(user_input == 'y' || user_input == 'Y')
    {
      clean_up();
      std::cout << "Terminate MWS Store?";
      std::cin >> user_input;
      if(user_input == 'y' || user_input == 'Y')
	{
	  terminate_MWS_Store();
	} else
	{
	std::cout << "Goodbye...";
	std::cin.ignore();
	}
    } else
    {
      std::cout << "Terminate MWS Store?";
      std::cin >> user_input;
      if(user_input == 'y' || user_input == 'Y')
	{
	  terminate_MWS_Store();
	} else
	{
	std::cout << "Goodbye...";
	std::cin.ignore();
	}
    }
  return 0;
}

int terminate_MWS_Store()
{
  std::cin.clear();
  std::string store;
  std::cout << "Enter the store number: ";
  std::cin >> store;
  std::string cmd("psexec \\\\fce-");
  cmd += store;
  cmd += " -u helpdesk -p LimeCoke taskkill /f /im MWSStore.exe";
  
  system(cmd.c_str());

  return 0;
}

int clean_up()
{
  std::cin.clear();
  std::string store;
  std::cout << "Enter the store number: ";
  std::cin >> store;
  std::string cmd("psexec \\\\fce-");
  cmd += store;
  cmd += " -u helpdesk -p LimeCoke C:\\Install\\clean_up.bat";
  
  system(cmd.c_str());

  return 0;
}
