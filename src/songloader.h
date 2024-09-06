#include <FreeImage.h>
#include <glib.h>
#include <gio/gio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libavformat/avformat.h>
#include "cache.h"
#include "chafafunc.h"
#include "file.h"
#include "sound.h"
#include "soundcommon.h"
#include "utils.h"

#ifndef MAXPATHLEN
#define MAXPATHLEN 4096
#endif

#ifndef KEYVALUEPAIR_STRUCT
#define KEYVALUEPAIR_STRUCT

typedef struct
{
        char *key;
        char *value;
} KeyValuePair;

#endif

#ifndef TAGSETTINGS_STRUCT
#define TAGSETTINGS_STRUCT

typedef struct
{
        char title[256];
        char artist[256];
        char album_artist[256];
        char album[256];
        char date[256];
} TagSettings;

#endif

#ifndef SONGDATA_STRUCT
#define SONGDATA_STRUCT

typedef struct
{
        gchar *trackId;
        char filePath[MAXPATHLEN];
        char coverArtPath[MAXPATHLEN];
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        TagSettings *metadata;
        FIBITMAP *cover;
        double duration;
        bool hasErrors;
} SongData;

#endif

extern Cache *tempCache;

SongData *loadSongData(char *filePath);
void unloadSongData(SongData **songdata);
