
TEMPLATE = subdirs
SUBDIRS =
win32 {
  SUBDIRS += rcsc
}
#SUBDIRS +=rcsc
SUBDIRS += src
CONFIG+=static

DISTFILES += \
	AUTHORS \
	COPYING \
	ChangeLog \
	NEWS \
	NEWS.en \
