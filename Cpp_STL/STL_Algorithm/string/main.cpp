#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // create an array
    string arr[] = { "prog.dat", "mydir", "hello.", "oops.tmp", "end.dat" };
    string filename, basename, extname, tmpname;
    const string suffix("tmp");

    /*
     * for each command-line argument
     * (which is an ordinary C-string)
    */
    for (int i = 1; i != sizeof(arr) / sizeof(arr[0]); ++i)
    {
        // process argument as file name
        filename = arr[i];

        // search period in fil ename
        string::size_type idx = filename.find('.');
        if (idx == string::npos)
        {
            // file name does not contain any period
            tmpname = filename + '.' + suffix;
        }
        else
        {
            /* split file name into base name and extension
             * - base name contains all characters before the period
             * - extension contains all characters after the period
            */
            basename = filename.substr(0, idx); // [0, idx)   -----exclude idx
            extname = filename.substr(idx + 1); // from idx + 1 to the end of the string
            if (extname.empty())
            {
                tmpname = filename;
                tmpname += suffix;
            }
            else if (extname == suffix)
            {
                // replace extension tmp with xxx
                tmpname = filename;
                tmpname.replace(idx + 1, extname.size(), "xxx");//equal to tmpname.replace(idx + 1, string::npos, "xxx");
            }
            else
            {
                // replace any extension with tmp
                tmpname = filename;
                tmpname.replace(idx + 1, extname.size(), suffix);//equal to tmpname.replace(idx + 1, string::npos, "xxx");
            }
        }

        // print file name and temporary name
        cout << filename << " => " << tmpname << endl;
    }


    return 0;
}
