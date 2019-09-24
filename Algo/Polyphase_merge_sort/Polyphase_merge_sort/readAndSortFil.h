#pragma once

using namespace std;

void outF(vector<string> &a, fstream &b);
void mergeFileAndVec(vector<string> &wh, fstream &in, fstream &out);
void mergeFiles(fstream &in1, fstream &in2, fstream &out);
void tempFilesOp(vector<string> &work, int &counter);
void rewriteToOut(int c);
