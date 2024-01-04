#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

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
        if (cin.fail())
        {
            cout << "Please enter a valid input in the form fileName.txt" << endl;
            continue;
        }
        followersFile.open(followersInput);
        if (followersFile.fail())
        {
            cout << "No file named "<< followersInput <<" exists. Please enter a valid input in the form fileName.txt" << endl << endl;
        }
        else
        {
            doneFollowers = true;
        }
    }

    bool doneFollowing = false;
    while (!doneFollowing)
    {
        cout << "Enter the name of the text file containing who you're FOLLOWING: ";
        cin >> followingInput;
        if (cin.fail())
        {
            cout << "Please enter a valid input in the form fileName.txt" << endl;
            continue;
        }
        followingFile.open(followingInput);
        if (followingFile.fail())
        {
            cout << "No file named "<< followingInput <<" exists. Please enter a valid input in the form fileName.txt" << endl << endl;
        }
        else
        {
            doneFollowing = true;
        }
    }
    cout << endl;

    // odd numbered lines of following and follower txt files are the username. even numbered lines is the date

    vector<string> followers;
    vector<string> following;
    int count = 1;
    string line;

    // first, store all usernames of followers and following into 2 vectors to later compare
    while (getline(followersFile, line))
    {
        if (count % 2 != 0) // odd number, so store the username into the followers vector
        {
            followers.push_back(line);
        }
        count++;
    } 

    count = 1;
    while (getline(followingFile, line))
    {
        if (count % 2 != 0) // odd number, so store the username into the following vector
        {
            following.push_back(line);
        }
        count++;
    }
    
    int counter = 0; // keep track of iterating thru all following usernames
    int linee=1; // who ur following. should = ur actual "following" number on instagram

    cout << "RESULTS: " << endl;
    while (following.size() > counter) // iterate thru everyone ur following
    {
        string followingUsername = following[counter];
        bool found = false;
        int followersCounter = 0;
        while (followersCounter < followers.size()) // iterate thru all ur followers to check if person x ur following is a follower
        {
            if (followingUsername == followers[followersCounter])
            {
                found = true;
                // cout << "ur following " << linee << " " << followingUsername << " and " << followers[followersCounter] << " is following back "<< endl;
                linee++;
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