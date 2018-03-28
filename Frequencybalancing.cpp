
//header files sections
#include <iostream>
#include <vector>

using namespace std;

//using this struct to store all the words and frequencies
struct TokenFreq {
    int freq;
    string token;
};

//To identify the least frequent letter
//This void functions will take paragraph input and finds out the frequency of each word in the paragraph
void getLeastFreqLetter(string p) {
    int alphabets [26];
    int index = 1;
    int min = 1;
    char characterholder = 'a';
    vector<char> holdfreq;
    
    //creating a for loop for all the 26 alphabets
    for(int i = 0;i<26;i++) {
        alphabets[i] = 0;
    }
    
    for(int i = 0;i<p.length();i++) {
        index = (p[i] - 97);
        if(index<=25&&index>=0) {
            alphabets[index]++;
        }
        
    }
    //To push values that equals the minimum
    for(int m = 0; m<26;m++) {
        if(alphabets[m]<=min && alphabets[m]!=0) {
            min = alphabets [m];
            characterholder = m+97;
            holdfreq.push_back(characterholder);
        }
        
    }
    //this will print out the lowest frequency
    for(int l = 0; l<holdfreq.size(); l++) {
        cout<<holdfreq[l]<<":"<<min<<endl;
    }
    
}


//Setting the number of tokens and delimiters which identifies all the unique tokens
vector<TokenFreq> getTokenFreq (string s) {
    int index = 0;
    string store;
    string store2;
    vector<TokenFreq> tokF(500);
    
//locating the spaces by removing any punctuation from the user input
    for(int i =0; i<s.length(); i++) {
        if(s[i] == ' '|| s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == '?'){
            if(s[i+1] == ' '){
                s.erase(i, 1);
            }
        }
    }
    
//looking for any punctuations and then once found it will combine all the elements together
    for(int j = 0;j<s.length();j++) {
        if(s[j] == ' '|| s[j] == '.' || s[j] == ',' || s[j] == ';' || s[j] == '?') {
            tokF[index].token = store;
            tokF[index].freq = 1;
            store.clear();
            index++;
            continue;
        }
        store += s[j];
    }
    tokF.resize(index);

//deletes all the duplicates and add to the original frequency
    for(int k = 0; k<tokF.size();k++) {
        store2 = tokF[k].token;
        for(int j= k+1; j<tokF.size();j++) {
            if(store2 == tokF[j].token){
                tokF[k].freq++;
                tokF.erase(tokF.begin()+j);
                j--;
            }
        }
    }

//Prints out the contents to the user
    cout<<endl;
    for(int q = 0; q<tokF.size();q++){
        cout<<tokF[q].token<<":"<<tokF[q].freq<<endl;
    }
    
    return tokF;
}

//start main function to run the program by asking user to input something
int main() {
    string statement;
    cout<<"Enter any statements:\n";
    getline(cin, statement);
    

    getLeastFreqLetter(statement);
    getTokenFreq(statement);
    
    return 0;
}
