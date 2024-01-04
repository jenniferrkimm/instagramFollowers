# instagramFollowers
A simple C++ program that tells you the username(s) of the account(s) that don't follow you back 💀
<br>  
## preliminary steps:

git clone this repository, which is named instagramFollowers. Then,
1. Log into your account on instagram.com
2. Navigate to and click on this icon: &nbsp; ![image of the hamburger icon](hamburger.png)
3. Click on `Your activity` > `Download your information`. This will take you to Meta's accounts center.
4. Click on `Download your information`, and follow the instructions to request a download. <br>For this program's purposes, simply clicking `Select types of information` > `Followers and following` and specifying the date range to "All time" is sufficient.
<br>
You will then get an email containing:
<br>
&nbsp; - a file of all the usernames you follow and the time you followed them
<br>
&nbsp;
- another file of all the usernames that follow you and the time they followed you
<br><br>
NOTE: this data will be displayed with each username on one line and the respective date/ time on a new line.
## post data download steps:

1. From the file that contains data of who you're following, copy its entire contents and paste it into a new text file with a title of your choosing (i.e following.txt).
2. Repeat the above step with the file that contains data of who is following you, pasting its contents into a new text file with a different title (i.e followers.txt)
<br><br>
NOTE: followersSample.txt and followingSample.txt are example files of what the structure of your text files should look like after pasting (username and date on separate lines). You can input those text files in the actual program, which rightfully displays mikePence and joeBiden not following back.

3. Type `g++ -std=c++17 program.cpp -o results` in the terminal. Then type `./results` to view the results of the usernames who aren't following you back.


