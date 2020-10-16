#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string secret_message(string s, int size) {
  vector<vector<char>> v;
  v.resize(size, vector<char>(size));

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) 
      v[i][j] = s[(i*size)+j]; 
  }

  string code = "";

  for(int i = 0; i < size; i++) {
    for(int j = size-1; j >= 0; j--) {
      char temp = v[j][i];
      if(temp != '*') 
        code += temp;
    }
  }

  return code;
}

int main() {
  int n;
  cin >> n;

  vector<string> code_words;

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int size = ceil(sqrt(s.length()));

    while(s.length() < pow(size, 2))
      s.push_back('*');

    code_words.push_back(secret_message(s, size));
  }

  for(int i = 0; i < code_words.size(); i ++)
    cout << code_words[i] << endl;
}
