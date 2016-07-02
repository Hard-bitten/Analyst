
TEMPLATE = subdirs
SUBDIRS =
win32 {
  SUBDIRS += rcsc
}
SUBDIRS += src

DISTFILES += \
	AUTHORS \
	COPYING \
	ChangeLog \
	NEWS \
	NEWS.en \
