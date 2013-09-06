#ifndef DOCUMENTINFORMATION_H
#define DOCUMENTINFORMATION_H

#include "document_global.h"
#include <QString>

#include "global/global.h"

class DOCUMENTSHARED_EXPORT DocumentInformation
{
public:
    DocumentInformation();
    void setAuthor(QString author) {this->author = author;}
    void setComments(QString comments) {this->comments = comments;}
    void setKeywords(QString keywords) {this->keywords = keywords;}
    void setTitle(QString title) {this->title = title;}
    void setSubject(QString subject) {this->subject = subject;}
    void setPublisher(QString publisher) {this->publisher = publisher;}
    void setDate(QString date) {this->date = date;}
    void setType(QString type) {this->type = type;}
    void setFormat(QString format) {this->format = format;}
    void setIdent(QString ident) {this->ident = ident;}
    void setSource(QString source) {this->source = source;}
    void setLanguageInfo(QString languageInfo) {this->languageInfo = languageInfo;}
    void setRelation(QString relation) {this->relation = relation;}
    void setCover(QString cover) {this->cover = cover;}
    void setRights(QString rights) {this->rights = rights;}
    void setContributor(QString contributor) {this->contributor = contributor;}
protected:
    QString author;
    QString comments;
    QString keywords;
    QString title;
    QString subject;
    QString publisher;
    QString date;
    QString type;
    QString format;
    QString ident;
    QString source;
    QString languageInfo;
    QString relation;
    QString cover;
    QString rights;
    QString contributor;
};

#endif // DOCUMENTINFORMATION_H
