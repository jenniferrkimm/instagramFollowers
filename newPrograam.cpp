#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/* populates the followers and following vectors from reading a file */
void appendVectorOG(ifstream& fileName, vector<string>& store, string line);
void appendVector(ifstream& fileName, vector<string>& store, string line);


/* if user enters multiple strings for an intended cin >> string variable,
this function clears the input for the next cin to function correctly at a clean slate */
void inputValid();

int main()
{
    ifstream followersFile; ifstream followingFile;
    string intro, followersInput, followingInput;
    cout << "Hello, welcome to instagramFollowers. Press enter to continue." << endl;
    getline(cin, intro);

    bool doneFollowers = false;
    while (!doneFollowers)
    {
        cout << "Enter the name of the text file containing your FOLLOWERS: ";
        cin >> followersInput;
        inputValid();

        if (cin.fail()) // likely won't be entered at all, but no harm in having it
        {
            cout << "Please enter a valid input in the form fileName.txt" << endl;
            continue;
        }
        followersFile.open(followersInput);
        if (followersFile.fail())
        {
            cout << "No file named "<< followersInput <<" exists. Please enter a valid input in the form fileName.txt" << endl << endl;
        }
        else doneFollowers = true;
    }

    bool doneFollowing = false;
    while (!doneFollowing)
    {
        cout << "Enter the name of the text file containing who you're FOLLOWING: ";
        cin >> followingInput;
        inputValid();

        if (cin.fail()) // likely won't be entered at all, but no harm in having it
        {
            cout << "Please enter a valid input in the form fileName.txt" << endl;
            continue;
        }
        followingFile.open(followingInput);
        if (followingFile.fail())
        {
            cout << "No file named "<< followingInput <<" exists. Please enter a valid input in the form fileName.txt" << endl << endl;
        }
        else doneFollowing = true;
    }
    cout << endl;

    vector<string> followers;
    vector<string> following;
    string line;

    // first, store all usernames of followers and following into 2 vectors to later compare
    appendVectorOG(followersFile, followers, line);
    appendVector(followingFile, following, line);
    
    int counter = 0; // keep track of iterating thru all following usernames
    int linee=1; // count of who ur following. should equal ur actual "following" number on instagram (USED FOR VALIDATION PURPOSES; can be commented out in final version along w lines 84 & 85)

    cout << "RESULTS: " << endl;
    while (following.size() > counter) // iterate thru everyone ur following
    {
        string followingUsername = following[counter];
        bool found = false;
        int followersCounter = 0;
        while (followersCounter < followers.size()) // iterate thru all ur followers to check if the <username> ur following is also a follower
        {
            if (followingUsername == followers[followersCounter])
            {
                found = true;
                // cout << "ur following " << linee << " " << followingUsername << " and " << followers[followersCounter] << " is following back "<< endl;
                // linee++;
                break;
            }
            followersCounter++;
        }
        if (!found) // not following u back!!!
        {
            cout << followingUsername << " is not following back" << endl;
        }
        counter++;
    }   
    return 0;
}


/*
  need to pass fileName by reference bc not having it attempts to copy an ifstream object,
  but ifstream objects have deleted copy constructors, so they cant be copied.
  Also, since youre modifying the contents of the vector, pass that by reference, too.
*/
void appendVectorOG(ifstream& fileName, vector<string>& store, string line)
{
    int count = 1;
    while (getline(fileName, line))
    {
      // NOTE: odd numbered lines of both the following and follower txt files are the usernames. even numbered lines are the dates. (we want the usernames only)
        if (count % 2 != 0) // ODD NUMBER, so store the username into the followers vector
        {
            store.push_back(line);
        }
        count++;
    } 
}
void appendVector(ifstream& fileName, vector<string>& store, string line)
{
    
    int count = 1;
    while (getline(fileName, line))
    {
        if ((count - 2) % 4 == 0 && count >= 2)
        {
            store.push_back(line);
        }
        count++;
    } 
}

void inputValid()
{
    cin.clear();
    string item;
    getline(cin, item);
}