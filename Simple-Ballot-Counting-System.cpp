// 5th January 2021
// Program to read ballots and count votes gained by 5 candidates

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class vote
{
     private:
          int *ballot, *voteCount;  // "ballot" array stores candidates' number as casted by voters and "voteCount" array stores number of votes gained by candidates
          int voters, spoiltBallot;
          string sym;
     public:
          vote()
          {
               sym = "\n*****************************************************************************************************\n";
               cout << sym << endl;

               cout << "\t\t\tEnter the number of voters = ";
               cin >> voters;

               spoiltBallot = 0;
               voteCount = new int[voters];
               for(int i = 0; i < voters; i++)
               {
                    voteCount[i] = 0;  // Initializing array with 0 ( replacing garbage values with 0's )
               } 
               ballot = new int[voters];
          }
          
          void castVotes()
          {
               cout << sym << endl;
               cout << "\tCast your vote by entering candidate number (1, 2, 3, 4 or 5) for respective candidates :- " << endl;
               for (int i = 0; i < voters; i++)
               {
                    cout << "\t\tEnter candidate number = ";
                    cin >> ballot[i];
               }
               cout << "\n\t\tThank you for casting your precious vote!" << endl;
               cout << sym << endl;
          }

          void countVotes()
          {
               for (int i = 0; i < voters; i++)
               {
                    int j = 0;
                    if (ballot[i] == 1)  // For Candidate 1
                    {
                         j = voteCount[0] + 1;  // 0 = 0 + 1 { if voteCounts' 0th index stores 0 } ...
                         voteCount[0] = j;
                    }
                    if(ballot[i] == 2)  // For Candidate 2
                    {
                         j = voteCount[1] + 1;
                         voteCount[1] = j;
                    }
                    if(ballot[i] == 3)  // For Candidate 3
                    {
                         j = voteCount[2] + 1;
                         voteCount[2] = j;
                    }
                    if(ballot[i] == 4)  // For Candidate 4
                    {
                         j = voteCount[3] + 1;
                         voteCount[3] = j;
                    }
                    if(ballot[i] == 5)  // For Candidate 5
                    {
                         j = voteCount[4] + 1;
                         voteCount[4] = j;
                    }
                    if(ballot[i] > 5 || ballot[i] == 0)  // For Spoilt votes
                    {
                         spoiltBallot++;
                    }
               }
          }

          void putResult()
          {
               cout << "\t\tThe results are = " << endl;
               cout << "\t\t\tCandidate 1 = " << voteCount[0] << endl;
               cout << "\t\t\tCandidate 2 = " << voteCount[1] << endl;
               cout << "\t\t\tCandidate 3 = " << voteCount[2] << endl;
               cout << "\t\t\tCandidate 4 = " << voteCount[3] << endl;
               cout << "\t\t\tCandidate 5 = " << voteCount[4] << endl;
               if(spoiltBallot > 0)
               {
                    cout << "\t\t\tSpoilt votes = " << spoiltBallot << endl;
               }
               cout << sym << endl;
               cout << "\t\tCongratulations!!!";
               
               if ((voteCount[0] > voteCount[1]) && (voteCount[0] > voteCount[2]) && (voteCount[0] > voteCount[3]) && (voteCount[0] > voteCount[4]))
               {
                    cout << "\n\t\t\tCandidate 1 wins election by " << voteCount[0] << " votes" << endl;
               }
               if((voteCount[1] > voteCount[0]) && (voteCount[1] > voteCount[2]) && (voteCount[1] > voteCount[3]) && (voteCount[1] > voteCount[4]))
               {
                    cout << "\n\t\t\tCandidate 2 wins election by " << voteCount[1] << " votes" << endl;
               }
               if((voteCount[1] > voteCount[0]) && (voteCount[2] > voteCount[1]) && (voteCount[2] > voteCount[3]) && (voteCount[2] > voteCount[4]))
               {
                    cout << "\n\t\t\tCandidate 3 wins election by " << voteCount[2] << " votes" << endl;
               }
               if((voteCount[3] > voteCount[0]) && (voteCount[3] > voteCount[1]) && (voteCount[3] > voteCount[2]) && (voteCount[3] > voteCount[4]))
               {
                    cout << "\n\t\t\tCandidate 4 wins election by " << voteCount[3] << " votes" << endl;
               }
               if((voteCount[4] > voteCount[0]) && (voteCount[4] > voteCount[1]) && (voteCount[4] > voteCount[2]) && (voteCount[4] > voteCount[3]))
               {
                    cout << "\n\t\t\tCandidate 5 wins election by " << voteCount[4] << " votes" << endl;
               }
               cout << sym;
          }
};

int main()
{
     vote batch1;
     batch1.castVotes();
     batch1.countVotes();
     batch1.putResult();
     
     return 0;
}