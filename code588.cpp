#include <bits/stdc++.h>
using namespace std;

class FSNode
{
public:
    bool isDir;
    virtual void fun() = 0;
};

class Directory : public FSNode
{

public:
    Directory()
    {
        isDir = true;
    }
    map<string, FSNode *> children;
    void fun()
    {
    }
};

class File : public FSNode
{
public:
    File()
    {
        isDir = false;
    }
    string content = "";
    void fun()
    {
    }
};

class FileSystem
{
    Directory *root;

public:
    FileSystem()
    {
        root = new Directory();
    }

    vector<string> ls(string path)
    {
        vector<string> tokens = tokenizePath(path);
        Directory *d = root;
        for (int i = 0; i < tokens.size(); i++)
        {
            FSNode *node = d->children[tokens[i]];
            if(!node->isDir) {
                return {tokens[i]};
            }
            d = dynamic_cast<Directory *>(node);
        }
        vector<string> children;
        for (std::map<string, FSNode *>::iterator it = d->children.begin(); it != d->children.end(); ++it)
        {
            children.push_back(it->first);
        }
        return children;
    }

    void mkdir(string path)
    {
        vector<string> tokens = tokenizePath(path);
        Directory *d = root;
        for (int i = 0; i < tokens.size(); i++)
        {
            FSNode *node = d->children[tokens[i]];
            if (node == nullptr)
            {
                node = new Directory();
                d->children[tokens[i]] = node;
            }
            d = dynamic_cast<Directory *>(node);
        }
    }

    void addContentToFile(string filePath, string content)
    {
        vector<string> tokens = tokenizePath(filePath);
        Directory *d = root;
        for (int i = 0; i < tokens.size() - 1; i++)
        {
            FSNode *node = d->children[tokens[i]];
            d = dynamic_cast<Directory *>(node);
        }
        string filename = tokens[tokens.size() - 1];
        FSNode *fNode = d->children[filename];
        if (fNode == nullptr)
        {
            fNode = new File();
            d->children[filename] = fNode;
        }
        File *f = dynamic_cast<File *>(fNode);
        f->content += content;
    }

    string readContentFromFile(string filePath)
    {
        vector<string> tokens = tokenizePath(filePath);
        Directory *d = root;
        for (int i = 0; i < tokens.size() - 1; i++)
        {
            FSNode *dNode = d->children[tokens[i]];
            d = dynamic_cast<Directory *>(dNode);
        }
        string filename = tokens[tokens.size() - 1];
        FSNode *fNode = d->children[filename];
        File *f = dynamic_cast<File *>(fNode);
        return f->content;
    }

    vector<string> tokenizePath(string path)
    {
        vector<string> tokens;
        string cur = "";
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                if (cur != "")
                    tokens.push_back(cur);
                cur = "";
            }
            else
                cur += path[i];
        }
        if (cur != "")
            tokens.push_back(cur);
        return tokens;
    }
};

void print_vec(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    FileSystem fs;
    fs.mkdir("/goowmfn");
    fs.ls("/goowmfn");
    fs.ls("/");
    fs.mkdir("/z");
    fs.ls("/");
    fs.ls("/");
}

/*

["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]



["addContentToFile","ls","ls","ls"]
[["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]


*/