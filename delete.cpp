#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;
bool deleteFolder(const std::string &folderPath)
{
    DIR *dir = opendir(folderPath.c_str());
    if (dir == nullptr)
    {
        std::cerr << "Error opening folder: " << folderPath << std::endl;
        return false;
    }
    dirent *entry;
    while ((entry = readdir(dir)) != nullptr)
    {
        if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        std::string filePath = folderPath + "/" + entry->d_name;

        if (entry->d_type == DT_DIR)
        {
            deleteFolder(filePath); // Recursively delete subdirectories
        }
        else
        {
            if (std::remove(filePath.c_str()) != 0)
            {
                std::cerr << "Error deleting file: " << filePath << std::endl;
                closedir(dir);
                return false;
            }
        }
    }

    closedir(dir);

    if (std::remove(folderPath.c_str()) != 0)
    {
        std::cerr << "Error deleting folder: " << folderPath << std::endl;
        return false;
    }

    std::cout << "Folder deleted successfully." << std::endl;
    return true;
}
void deleteFile(string &filename)
{
    cout << "Deleting file: " << filename << endl;
    remove(filename.c_str());
}
signed main()
{
    string type;
    cout << "What do you want to delete file or folder: ";
    cin >> type;
    for (int i = 0; i < type.size(); i++)
    {
        type[i] = tolower(type[i]);
    }
    if (type == "file" or type == "1" or type == "fl")
    {
        string fname;
        while (cin >> fname)
        {
            if (fname == "quit")
            {
                return 0;
            }
            string filename = fname;
            std::chrono::system_clock::time_point scheduledTime = std::chrono::system_clock::now() + std::chrono::seconds(0);
            std::this_thread::sleep_until(scheduledTime);
            deleteFile(filename);
        }
    }
    if (type == "folder" or type == "2" or type == "fd" or type == "flder" or type == "fder")
    {
        string fname;
        while (cin >> fname)
        {
            string foldername = fname;
            if (fname == "quit")
            {
                return 0;
            }

            else if (deleteFolder(foldername))
            {

                cout << "Folder " << foldername << " deletion succeeded"
                     << "\n";
            }
            else
            {
                cout << "Folder " << foldername << " deletion failed"
                     << "\n";
            }
        }
    }

    return 0;
}