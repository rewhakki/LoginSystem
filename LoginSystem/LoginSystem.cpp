#include <iostream>
#include <fstream>
#include <string>


bool IsLoggedIn()
{
    std::string username, password, chckUn, chckPw;

    std::cout << "\nEnter login: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    //CHANGE THE LOCATION PATH AND DATA FOLDER NAME!!!
    std::ifstream read("D:\LoginSystemData\\" + username + ".txt"); //Read login-file
    getline(read, chckUn); //Read login
    getline(read, chckPw); //Read password

    if (chckUn == username && chckPw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    std::cout << "Welcome to the Hakki Login System! \n\n1. Register \n2. Login \n3. Delete Account \nEnter your choice: ";
    std::cin >> choice;

    if (choice == 1) //REGISTER SYSTEM
    {
        std::string username, password;

        std::cout << "\nEnter login: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        //CHANGE THE LOCATION PATH AND DATA FOLDER NAME!!!
        std::fstream chckFile("D:\LoginSystemData\\" + username + ".txt", std::ios::in); //init check file var

        if (chckFile.is_open()) //File with that name was found!
        {
            std::cout << "Username is already exists!";
            return 0;
        }

        else //File with that name was NOT found! Create new file!
        {
            std::ofstream file; //Init file var

            //CHANGE THE LOCATION PATH AND DATA FOLDER NAME!!!
            file.open("D:\LoginSystemData\\" + username + ".txt"); //Open file

            file << username << std::endl << password; //Write data in file
            file.close();   //Close file

            std::cout << "Account " << username << " create!\n\n";

            main();
        }

    }

    if (choice == 2) //LOGIN SYSTEM
    {
        bool status = IsLoggedIn(); //Check True/False

        if (!status) //If FALSE
        {
            std::cout << "\nWrong login or password!";
            system("PAUSE");
            return 0;
        }
        else //If TRUE
        {
            std::cout << "\nLogin was successfully!\n";
            system("PAUSE");
            return 1;
        }

    }

    if (choice == 3) //DELETE ACCOUNT SYSTEM
    {
        std::string username, password;
        std::cout << "\nEnter the login of the account you want to delete: ";
        std::cin >> username;

        std::cout << "Do you want to delete your account " << username << "?" << std::endl;
        std::cout << "1. Yes \n2. No \nEnter your choice: ";

        std::cin >> choice;

        switch (choice)
        {
            case 1: //Delete
                //CHANGE THE LOCATION PATH AND DATA FOLDER NAME!!!
                remove(("D:\LoginSystemData\\" + username + ".txt").c_str()); //Deleting file from folder
                std::cout << "\nAccount " << username << " was deleted!";
                return 0;
                break;

            case 2: //Don`t delete
                std::cout << "\nAccount " << username << " was not deleted!";
                return 0;
                break;

            default: //Other choice
                std::cout << "\nWrong choice!";
                return 0;
                break;
        }
    }
}