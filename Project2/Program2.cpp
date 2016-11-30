//Zach Brown
//2/11/2015
//Program2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Team
{
    string teamname;

private:
    string teamName;
    int numOfGamesPlayed;
    int numOfGamesWon;
    vector<int> scores;

public:
    Team()
    {
        numOfGamesPlayed = 0;
        numOfGamesWon = 0;
        scores ;
    }
        
    Team(string a);
    void setteamName(string team)
    {
        teamName = team;
    }
    void setnumOfGamesPlayed()
    {
        numOfGamesPlayed = numOfGamesPlayed + 1;
    }
    void setnumOfGamesWon()
    {
        numOfGamesWon = numOfGamesWon + 1;
    }
    void setScores(int s)
    {
   
        scores.push_back(s);
    }
    string getTeamName()
    {
        return teamName;
    }
    int getnumOfGamesPlayed()
    {
        return numOfGamesPlayed;
    }
    int  getnumOfGamesWon()
    {
        return numOfGamesWon;
    }
    int getscores(int position)
    {
      return  scores[position];
    }



};

int main()
{
    int numberOfTeams;

    Team teamsArray[16];//Array for teams
    int inputArrayI[200];//Array for scores of each game
    string inputArrayS[200];//Array for teamsnames that played a game


//#########opening user requested file#######################################
    string fileName;
    cout << "What is the name of the input file?";
    getline(cin,fileName);
    ifstream fin;
    fin.open(fileName.c_str());
    while (!fin.is_open())//eeror checking for making sure the file is opened
    {
        cout << "The file could not open. Please enter the correct file: ";
        getline(cin, fileName);
        ifstream fin;
        fin.open(fileName.c_str());
        if (fin.is_open())//if file is opened, this will brek out of the error checking
        {
            break;
        }

    }
   string outname;
   cout << "What is the name of the output file?";
   getline(cin, outname);
   ofstream fout(outname);
//#################### end oping user requested file #########################



    fin >> numberOfTeams;//taking in the first line of the file 
    int counter = 0;
    while (counter < numberOfTeams)//loop for reading the teams and putting them into an array
    {
        string tempteamname;
        fin >> tempteamname;

        teamsArray[counter].setteamName(tempteamname);
        counter++;
    }



    int counter2 = 0;
    while (!fin.eof())//loop for putting the teams and scores into their own arrays || index for team played and score will be the same index for the two arrays
    {
        fin >> inputArrayS[counter2];

        fin >> inputArrayI[counter2];
        counter2++;
    }
    

    for (int i = 0; i < counter2; i++)// adding games played
    {
        for (int w = 0; w < numberOfTeams; w++)//interating through each team
        {
            if (inputArrayS[i] == teamsArray[w].getTeamName())// if the name in each index of the two arrays match then that team gets ++ to agmes played 
            {
                teamsArray[w].setnumOfGamesPlayed();
                
            }
        }
    }
    int counter3 = 0;
    for (int i = 0; i < counter2; i++)//adding scores from each game into the right team
    {
        for (int w = 0; w < numberOfTeams; w++)
        {

            if (inputArrayS[i] == teamsArray[w].getTeamName())
            {
                int score = inputArrayI[i];
                teamsArray[w].setScores(score);
            }
        }
    }



    for (int i = 0; i < counter2 ; i=i+2)//assesing and assinging games won to the correct
    {        
        if (inputArrayI[i] > inputArrayI[i + 1])//seeing who won
        {
            for (int w= 0; w < numberOfTeams; w ++)//interating through each team
            {
                if (inputArrayS[i] == teamsArray[w].getTeamName())// if the name in each index of the two arrays match then that team gets ++ to their wins
                {
                    teamsArray[w].setnumOfGamesWon();
                }
            }
           
        
        }
        else// SAME LOGIC ^^^^^^^^
        {
            for (int p = 0; p < numberOfTeams; p++)
            {
                if (inputArrayS[i+1] == teamsArray[p].getTeamName())
                {
                    teamsArray[p].setnumOfGamesWon();
                }
            }
           
        }
        
    }
    string tempwinner;// code for seeing who won the most games
    string winner;
    string temploser;
    string loser ;
    int templint1 = 0;
    int templint2 = 0;
    int tempint1 = 0;
    int tempint2 = 0;
    for (int i = 0; i < numberOfTeams; i++)
    {
        for (int j = 0; j < numberOfTeams; j++)
        {
            if (teamsArray[i].getnumOfGamesWon() > teamsArray[j].getnumOfGamesWon())
            {
                tempwinner = teamsArray[i].getTeamName();
                tempint1 = teamsArray[i].getnumOfGamesWon();
                temploser = teamsArray[j].getTeamName();
                templint1 = teamsArray[j].getnumOfGamesWon();
                

            }
            if (teamsArray[i].getnumOfGamesWon() < teamsArray[j].getnumOfGamesWon())
            {
                if (teamsArray[j].getnumOfGamesWon() > tempint2)
                {
                    tempint2 = teamsArray[j].getnumOfGamesWon();
                    winner = teamsArray[j].getTeamName();
                    break;
                }
               if (teamsArray[i].getnumOfGamesWon() <= templint2)
                    {
                        loser = teamsArray[i].getTeamName();
                        templint2 = teamsArray[i].getnumOfGamesWon();
                       
                        break;
                    }
               }
            
        }
    }


    if (tempint1 > tempint2)
    {
        winner = tempwinner;
        tempint2 = tempint1;
    }


    if (templint1 <= templint2)
    {
        loser = temploser;
        templint2 = templint1;
    }
    double avgscorewinner = 0;// average for winning team
    for (int i = 0; i < numberOfTeams; i++)
    {
        if (winner == teamsArray[i].getTeamName())
        {
            for (int k = 0; k < teamsArray[i].getnumOfGamesPlayed(); k ++)
            {
                avgscorewinner = avgscorewinner + teamsArray[i].getscores(k);
              
            }
            avgscorewinner = avgscorewinner / teamsArray[i].getnumOfGamesPlayed();
        }
    }
    double avgscoreloser = 0;// average for losing team
    for (int i = 0; i < numberOfTeams; i++)
    {
        if (loser == teamsArray[i].getTeamName())
        {
            
            for (int k = 0; k < teamsArray[i].getnumOfGamesPlayed(); k++)
            {
                avgscoreloser = avgscoreloser + teamsArray[i].getscores(k);
            }
           avgscoreloser = avgscoreloser / teamsArray[i].getnumOfGamesPlayed();
        }
    }
    
    fout << "Sportsball Statistics Sheet" << endl << endl << endl << "Best team:" << endl << winner << endl <<// stat sheet
        " won " << tempint2 << " games this season " << endl << "Their average score was " << avgscorewinner << "." <<
        endl << endl << "Worst team:" << endl << loser << endl << "Won " << templint2 <<
        " games this season" << "." << endl << "Their average score was " << avgscoreloser << "." << endl;


  



}

Team::Team(string a)//constuctor for Team
{
    teamName = a;
   

}