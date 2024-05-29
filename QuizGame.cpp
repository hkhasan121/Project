#include<bits/stdc++.h>
using namespace std;


int quizPlay()
{
    char option;
    int score = 0;
    cout<<"-------- Welcome to Quiz Game --------"<<endl;
    cout<<"------ Please follow the instructions ------"<<endl;
    cout<<"Step 1 : Quiz contains total 5 questions "<<endl;
    cout<<"Step 2 : You will be given 1 mark for each right answer"<<endl;
    cout<<"Step 3 : There will be no negative marking"<<endl;
    cout<<"Step 4 : Please press S to start the Quiz"<<endl;
    cout<<"Step 5 : Please select an option between a , b , c , d"<<endl;
    cout<<"Step 6 : If score is greater than or qual 3, then you will pass the Quiz"<<endl;

    char c;
    cin>>c;

    while(c != 'S' && c != 's')
    {
        cout<<"You have entered wrong character, Please press S"<<endl;
        cin>>c;
    }


    if(c == 'S' || c == 's')
    {
        cout<<"Q1. What is the capital of Bangladesh? "<<endl;
        cout<<" (a) Dhaka   (b) Rajshahi   (c) Barisal   (d) Jahangirnagar "<<endl;
        cin>>option;
        if(option == 'a' || option == 'A')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout<<"Q2. What are the official language of Bangladesh? "<<endl;
        cout<<" (a) English   (b) Urdu   (c) Hindi   (d) Bangla "<<endl;
        cin>>option;
        if(option == 'd' || option == 'D')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }
        cout<<"Q3. What is the total border area of Bangladesh? "<<endl;
        cout<<" (a) 238 km   (b) 4144 km   (c) 5138 km   (d) 711 km "<<endl;
        cin>>option;
        if(option == 'c' || option == 'C')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }
        cout<<"Q4. How many districts are there in Bangladesh? "<<endl;
        cout<<" (a) 64   (b) 213   (c) 88   (d) 121 "<<endl;
        cin>>option;
        if(option == 'a' || option == 'A')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout<<"Q5. How many unions are there in Bangladesh? "<<endl;
        cout<<" (a) 4562   (b) 4560   (c) 4662   (d) 4552 "<<endl;
        cin>>option;
        if(option == 'a' || option == 'A')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

    }



    return score;
}

void playAgain()
{
    int result = 0;
    bool firstRun = true;
    string playAgain;

    while(firstRun || playAgain == "yes "  || playAgain == "YES")
    {
        result = quizPlay();
        cout<<"Your score is : "<<result<<endl;
        if(result >= 3)
        {
            cout<<"You are passed !!!"<<endl;

        }
        else
        {
            cout<<"You are failed"<<endl;
        }

        cout<<"Do you wan to play Quiz again ?? ( yes or no )"<<endl;
        cin>>playAgain;

        firstRun = playAgain == "yes" || playAgain == "YES";

        }

        cout<<"Thank you for playing the Quiz !"<<endl;

    }



int main()
{
     playAgain();


}
