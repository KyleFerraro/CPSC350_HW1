// Kyle Ferraro
// Student ID: 2302544
// Homework 1
//2-25-2020

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Set the variables to be stored as their unique methods in order to not do again
int count_A, count_C, count_T, count_G;
float prob_A, prob_C, prob_T, prob_G;
int count_AA, count_AC, count_AT, count_AG;
int count_CA, count_CC, count_CT, count_CG;
int count_TA, count_TC, count_TT, count_TG;
int count_GA, count_GC, count_GT, count_GG;
float prob_AA, prob_AC, prob_AT, prob_AG;
float prob_CA, prob_CC, prob_CT, prob_CG;
float prob_TA, prob_TC, prob_TT, prob_TG;
float prob_GA, prob_GC, prob_GT, prob_GG;
int num_lines, sum_DNA, lines, line_count;
float mean, var, std_dev, temp_var;


int main(int argc, char** argv){
    ifstream inFS; //input file stream
    string f_name = argv[1];

    //getting data from the file
    cout << "Please enter the file name: " << endl;
    cin >> f_name;

    //inFS.open(f_name);
    //attempted to open file for whole program, rather than reopening it

    getline(cin, f_name);
    //extracts charaxters from file (cplisplus.com)
    

    //attempting to count the amount of lines in order to compute mean later
    void count_lines(std::string fileName) {
        inFS.open(f_name);
        //open file for function
        if(!file.is_open()) {
            cout << "Unable to open file: " << f_name << endl;
            return 1;
            //checks to see if file is actually able to open
        }
        string line;
        num_lines = 0;
        while(getline(file, line)) {
            ++num_lines;
        }
        //close the file
        inFS.close(f_name);
        
    }

    //calculates the length of each string in the .txt file to find sum
    void sum_lines(string f_name){
        inFS.open(f_name);
        if(!file.is_open()) {
            cout << "Unable to open file: " << f_name << endl;
            return 1;
        }
        string line;
        sum_DNA = 0;

        while(getline(file, line)) {
            //used to find out how many nucleotides are in a DNA string
            for(int i=0; i<lines.length(); i++) {
                ++sum_DNA;
            }
        }
        inFS.close(f_name);

    }


    mean = (sum_DNA/num_lines);
    //no need to make a function for the mean since we just use variables
    //and numbers from previous functions


    //Calculate the variance of the strings in the inputfile
    void var_DNA(string f_name){
        inFS.open(f_name);
        if(!file.is_open()) {
            cout << "Unable to open file: " << f_name << endl;
            return 1;
        }
        mean_sqr = 0;
            
         while(getline(file, line)){
            //finds length of line and subtracts from the mean
            temp_var = (line.length() - mean);    
            //squares the differences          
            mean_sqr += (temp_var*temp_var);
            //adds the squared mean_sqr together
            ++line_count;
        }
        //calculates the variance by dividing by the number of strings
        var = (mean_sqr/line_count);
        inFS.close(f_name);
    }

    //no need to make a function to find standard deviation
    //since we just use previous values from our functions
    std_dev = sqrt(var);


    //calculating the probability of each nucleotide's occurrences
    void prob_nucleotide(string f_name){
        inFS.open(f_name);
        if(!file.is_open()) {
            cout << "Unable to open file: " << f_name << endl;
            return 1;
        }

        string line;
        count_A = 0;
        count_C = 0;
        count_T = 0;
        count_G = 0;

        //Going through each differnet letter and counting each occurence and
        //add them to the values above
        while(getline(file, line)) {
            //sets every letter to lowercase, so no complications occur
            char line = tolower(line);
            for(int i=0; i<line.length(); ++i) {
                if(line[i] == 'a'){
                    ++count_A;
                }
                else if(line[i] == 'c'){
                    ++count_C;
                }
                else if(line[i] == 't'){
                    ++count_T;
                }
                else if(line[i] == 'g'){
                    ++count_G;
                }
            }
        }
        inFS.close(f_name);

        //calculating the probability by dividing the occurences by the 
        //sum of every nucleotide
        prob_A = count_A/sum_DNA;
        prob_C = count_C/sum_DNA;
        prob_T = count_T/sum_DNA;
        prob_G = count_G/sum_DNA;

    }


    //calculating the probability of each nucleotide bigram occurrences
    void prob_nucleotide_bigram(string f_name){
        inFS.open(f_name);
        if(!file.is_open()) {
            cout << "Unable to open file: " << f_name << endl;
            return 1;
        }
        string line;
        count_AA = 0;
        count_CA = 0;
        count_TA = 0;
        count_GA = 0;
        count_AC = 0;
        count_CC = 0;
        count_TC = 0;
        count_GC = 0;
        count_AT = 0;
        count_CT = 0;
        count_TT = 0;
        count_GT = 0;
        count_AG = 0;
        count_CG = 0;
        count_TG = 0;
        count_GG = 0;

    //Going through each differnet letter (and the following) and 
    //counting each occurence and add them to the values above
        //Double nested for loop to go through each varaiable to determine
        //their bigram and counting for the amount of occurences
        while(getline(file, line)) {
            char line = tolower(line);
            for(int i=0; i<line.length(); ++i) {
                if(line[i] == 'a'){
                    if(line[i+1] == 'a'){
                        ++count_AA;
                    }
                    else if(line[i+1] == 'c'){
                        ++count_AC;
                    }
                    else if(line[i+1] == 't'){
                        ++count_AT;
                    }
                    else if(line[i+1] == 'g'){
                        ++count_AG;
                    }

                }
                else if(line[i] == 'c'){
                    if(line[i+1] == 'a'){
                        ++count_CA;
                    }
                    else if(line[i+1] == 'c'){
                        ++count_CC;
                    }
                    else if(line[i+1] == 't'){
                        ++count_CT;
                    }
                    else if(line[i+1] == 'g'){
                        ++count_CG;
                    }
                    
                }
                else if(line[i] == 't'){
                    if(line[i+1] == 'a'){
                        ++count_TA;
                    }
                    else if(line[i+1] == 'c'){
                        ++count_TC;
                    }
                    else if(line[i+1] == 't'){
                        ++count_TT;
                    }
                    else if(line[i+1] == 'g'){
                        ++count_TG;
                    }
                }
                else if(line[i] == 'g'){
                    if(line[i+1] == 'a'){
                        ++count_GA;
                    }
                    else if(line[i+1] == 'c'){
                        ++count_GC;
                    }
                    else if(line[i+1] == 't'){
                        ++count_GT;
                    }
                    else if(line[i+1] == 'g'){
                        ++count_GG;
                    }
                    
                }
            }
        }
        inFS.close(f_name);


        //calculating the probability of each bigrams occurence by dividing 
        //total occurences by the sum of all occurences
        prob_AA= count_AA/sum_DNA;
        prob_AC = count_AC/sum_DNA;
        prob_AT = count_AT/sum_DNA;
        prob_AG = count_AG/sum_DNA;
        prob_CA = count_CA/sum_DNA;
        prob_CC = count_CC/sum_DNA;
        prob_CT = count_CT/sum_DNA;
        prob_CG = count_CG/sum_DNA;
        prob_TA = count_TA/sum_DNA;
        prob_TC = count_TC/sum_DNA;
        prob_TT = count_TT/sum_DNA;
        prob_TG = count_TG/sum_DNA;
        prob_GA = count_GA/sum_DNA;
        prob_GC = count_GC/sum_DNA;
        prob_GT = count_GT/sum_DNA;
        prob_GG = count_GG/sum_DNA;
    }
    inFS.close();


    //creating the output file and adding it to a new file named kyleferraro.txt
    ofstream outFS;
    outFS.open("kyleferraro.txt");
    if(!outFS.is_open()) {
        cout << "Kyle Ferraro" << endl;
        cout << "Student ID: 2302544" << endl;
        cout << "Homework 1 (2-25-2020)" << endl;

        //inputting each difffent value in based on the format of the example
        cout << "The Sum of the length of the DNA strings is: " << sum_DNA  << endl;
        cout << "The Mean of the length of the DNA strings is: " <<  mean << endl;
        cout << "The Variance of the length of the DNA strings is: " <<  var << endl;
        cout << "The Standard Deviation of the length of the DNA strings is: " <<   << endl;
        
        cout << "Here is the relative probability of each nucleotide:" << endl;
        cout << "A: " << prob_A << endl;
        cout << "C: " << prob_C << endl;
        cout << "T: " << prob_T << endl;
        cout << "G: " << prob_G << endl;
        
        
        cout << "Here is the relative probability of each nucleotide bigram:" << endl;
        cout << "AA: " << prob_AA << endl;
        cout << "AC: " << prob_AC << endl;
        cout << "AT: " << prob_AT << endl;
        cout << "AG: " << prob_AG << endl;
        cout << "CA: " << prob_CA << endl;
        cout << "CC: " << prob_CC << endl;
        cout << "CT: " << prob_CT << endl;
        cout << "CG: " << prob_CG << endl;
        cout << "TA: " << prob_TA << endl;
        cout << "TC: " << prob_TC << endl;
        cout << "TT: " << prob_TT << endl;
        cout << "TG: " << prob_TG << endl;
        cout << "GA: " << prob_GA << endl;
        cout << "GC: " << prob_GC << endl;
        cout << "GT: " << prob_GT << endl;
        cout << "GG: " << prob_GG << endl;    

    }

    
    
    return 0;

}


