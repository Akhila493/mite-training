#include<stdio.h>

void countVotes(int votes[], int n_votes, int candidateVotes[]){
    for(int i=0; i < n_votes; i++){
      if(votes[i]>=1 && votes[i]<=5){
        candidateVotes[votes[i]-1]++;
      }
    }
}

int findWinner(int candidateVotes[],int n_candidates){
    int max_votes = 0;
    int winnerIndex = 0;
    
    for(int i=0 ; i< n_candidates; i++){
        if(candidateVotes[i]>max_votes){
            max_votes = candidateVotes[i];
            winnerIndex = i;
        }
    }
    return winnerIndex;
}
int main() {
    int votes[20], candidateVotes[5] = {0}, n_votes,n_candidates;
    
    printf("Enter the number of Candidates: ");
    scanf("%d",&n_candidates);
    
    printf("Enter the number of Votes: ");
    scanf("%d", &n_votes);
    
    printf("\nEnter votes (1-5): ");
    for (int i = 0; i < n_votes; i++) {
        scanf("%d", &votes[i]);
    }
    
    countVotes(votes, n_votes, candidateVotes);
    int winnerIndex = findWinner(candidateVotes, n_candidates);
    
    for(int i=0;i < n_candidates; i++)
    {
        printf("Candidates %d votes are %d\n",i+1,candidateVotes[i]);
    }
    if (winnerIndex != -1) {
        printf("WINNER: Candidate %d\n", winnerIndex + 1);
    } else {
        printf("No votes were cast.\n");
    }
    
    return 0;
}
