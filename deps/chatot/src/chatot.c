////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <chatot/chatot.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

static ChatotSeverity _chatot_severity = CHATOT_SEVERITY_DEBUG;

////////////////////////////////////////////////////////////////////////////////
// Functions <chatot/chatot.h>
////////////////////////////////////////////////////////////////////////////////

void chatot_severity(ChatotSeverity severity)
{
    _chatot_severity = severity;
}

void chatot_chatter(ChatotSeverity severity, const char* message, ...)
{
    if (severity < _chatot_severity)
    {
        return;
    }

    switch (severity)
    {
        case CHATOT_SEVERITY_DEBUG:
        fprintf(stdout, "[Debug]   ");
        break;

        case CHATOT_SEVERITY_WARNING:
        fprintf(stdout, "[Warning] ");
        break;

        case CHATOT_SEVERITY_ERROR:
        fprintf(stdout, "[Error]   ");
        break;

        case CHATOT_SEVERITY_FATAL:
        fprintf(stdout, "[Fatal]   ");
        break;
    }

    va_list args;
    va_start(args, message);
    vfprintf(stdout, message, args);
    va_end(args);

    fprintf(stdout, "\n");

    if (severity == CHATOT_SEVERITY_FATAL)
    {
        exit(EXIT_FAILURE);
    }
}