#include "BackgroundImageContents.h"

BackgroundImageContents::BackgroundImageContents(string filename, GError** error)
{
	XOJ_INIT_TYPE(BackgroundImageContents);

	this->filename = filename;
	this->pixbuf = gdk_pixbuf_new_from_file(filename.c_str(), error);
}

BackgroundImageContents::BackgroundImageContents(GInputStream* stream, string filename, GError** error)
{
	XOJ_INIT_TYPE(BackgroundImageContents);

	this->filename = filename;
	this->pixbuf = gdk_pixbuf_new_from_stream(stream, nullptr, error);
}

BackgroundImageContents::~BackgroundImageContents()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	g_object_unref(this->pixbuf);
	this->pixbuf = NULL;

	XOJ_RELEASE_TYPE(BackgroundImageContents);
}

void BackgroundImageContents::unreference()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	this->ref--;
	if (this->ref < 0)
	{
		delete this;
	}
}

void BackgroundImageContents::reference()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	this->ref++;
}

string BackgroundImageContents::getFilename()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	return this->filename;
}

void BackgroundImageContents::setFilename(string filename)
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	this->filename = filename;
}

bool BackgroundImageContents::isAttach()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	return this->attach;
}

void BackgroundImageContents::setAttach(bool attach)
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	this->attach = attach;
}

int BackgroundImageContents::getPageId()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	return this->pageId;
}

void BackgroundImageContents::setPageId(int id)
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	this->pageId = id;
}

GdkPixbuf* BackgroundImageContents::getPixbuf()
{
	XOJ_CHECK_TYPE(BackgroundImageContents);

	return this->pixbuf;
}
