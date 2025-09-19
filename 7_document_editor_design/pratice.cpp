#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

class ImgElement : public DocElement
{
private:
    string imgPath;

public:
    ImgElement(string imgPath)
    {
        this->imgPath = imgPath;
    }

    string render() override
    {
        return "[Image: " + imgPath + "]";
    }
};

class Document
{
private:
    vector<DocElement *> docELements;

public:
    void addElement(DocElement *element)
    {
        docELements.push_back(element);
    }
    string render()
    {
        string result;
        for (auto element : docELements)
        {
            result += element->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");

        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        // Save to DB
    }
};

class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }
    void addImage(string imagePath)
    {
        document->addElement(new ImgElement(imagePath));
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument()
    {
        storage->save(renderDocument());
    }
};

int main()
{
    Document *document = new Document();
    Persistence *persistance = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistance);

    editor->addText("Hello World!");
    editor->addImage("pic.jpg");

    cout << editor->renderDocument() << endl;
    editor->saveDocument();
}