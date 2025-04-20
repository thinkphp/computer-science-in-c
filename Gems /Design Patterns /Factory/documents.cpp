#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Abstract Product
class Document {
protected:
    std::string name;
    std::string content;

public:
    Document() = default;
    virtual ~Document() = default;

    void setName(const std::string& name) {
        this->name = name;
    }

    void setContent(const std::string& content) {
        this->content = content;
    }

    std::string getName() const {
        return name;
    }

    std::string getContent() const {
        return content;
    }

    virtual void save() const = 0;
    virtual void preview() const = 0;
};

// Concrete Products
class PDFDocument : public Document {
public:
    void save() const override {
        std::cout << "Saving PDF document: " << name << std::endl;
        std::cout << "Compressing and encrypting content" << std::endl;
        // PDF-specific saving logic
    }

    void preview() const override {
        std::cout << "Previewing PDF document: " << name << std::endl;
        std::cout << "Content: " << content << std::endl;
    }
};

class WordDocument : public Document {
public:
    void save() const override {
        std::cout << "Saving Word document: " << name << std::endl;
        std::cout << "Formatting and spell-checking content" << std::endl;
        // Word document-specific saving logic
    }

    void preview() const override {
        std::cout << "Previewing Word document: " << name << std::endl;
        std::cout << "Content: " << content << std::endl;
    }
};

class HTMLDocument : public Document {
public:
    void save() const override {
        std::cout << "Saving HTML document: " << name << std::endl;
        std::cout << "Validating markup and formatting" << std::endl;
        // HTML-specific saving logic
    }

    void preview() const override {
        std::cout << "Rendering HTML document in browser: " << name << std::endl;
        std::cout << "Content: " << content << std::endl;
    }
};

// Abstract Creator
class DocumentFactory {
public:
    virtual ~DocumentFactory() = default;
    virtual std::unique_ptr<Document> createDocument() const = 0;
    
    // Template method that uses the factory method
    std::unique_ptr<Document> prepareDocument(const std::string& name, const std::string& content) const {
        std::unique_ptr<Document> document = createDocument();
        document->setName(name);
        document->setContent(content);
        return document;
    }
};

// Concrete Creators
class PDFDocumentFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() const override {
        return std::make_unique<PDFDocument>();
    }
};

class WordDocumentFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() const override {
        return std::make_unique<WordDocument>();
    }
};

class HTMLDocumentFactory : public DocumentFactory {
public:
    std::unique_ptr<Document> createDocument() const override {
        return std::make_unique<HTMLDocument>();
    }
};

// Document Management System
class DocumentManagementSystem {
private:
    std::vector<std::unique_ptr<Document>> documents;

public:
    void createDocument(const DocumentFactory& factory, const std::string& name, const std::string& content) {
        auto document = factory.prepareDocument(name, content);
        documents.push_back(std::move(document));
        std::cout << "Document '" << name << "' added to the system." << std::endl;
    }

    void listDocuments() const {
        std::cout << "\nDocument List:" << std::endl;
        std::cout << "--------------" << std::endl;
        if (documents.empty()) {
            std::cout << "No documents in the system." << std::endl;
            return;
        }

        for (size_t i = 0; i < documents.size(); ++i) {
            std::cout << i + 1 << ". " << documents[i]->getName() << std::endl;
        }
    }

    void previewDocument(size_t index) const {
        if (index >= 1 && index <= documents.size()) {
            std::cout << "\nPreviewing document:" << std::endl;
            documents[index - 1]->preview();
        } else {
            std::cout << "Invalid document index." << std::endl;
        }
    }

    void saveDocument(size_t index) const {
        if (index >= 1 && index <= documents.size()) {
            std::cout << "\nSaving document:" << std::endl;
            documents[index - 1]->save();
        } else {
            std::cout << "Invalid document index." << std::endl;
        }
    }

    void saveAllDocuments() const {
        std::cout << "\nSaving all documents:" << std::endl;
        if (documents.empty()) {
            std::cout << "No documents to save." << std::endl;
            return;
        }

        for (const auto& doc : documents) {
            doc->save();
            std::cout << "--------------" << std::endl;
        }
    }
};

// Client code
int main() {
    DocumentManagementSystem dms;
    PDFDocumentFactory pdfFactory;
    WordDocumentFactory wordFactory;
    HTMLDocumentFactory htmlFactory;

    // Create documents of different types
    dms.createDocument(pdfFactory, "Annual Report", "Financial data for 2023");
    dms.createDocument(wordFactory, "Meeting Minutes", "Topics discussed in April meeting");
    dms.createDocument(htmlFactory, "Company Website", "<html><body><h1>Welcome to our company</h1></body></html>");

    // List all documents
    dms.listDocuments();

    // Preview and save specific documents
    dms.previewDocument(1);  // Preview the first document (Annual Report)
    dms.saveDocument(2);     // Save the second document (Meeting Minutes)

    // Save all documents
    dms.saveAllDocuments();

    return 0;
}
