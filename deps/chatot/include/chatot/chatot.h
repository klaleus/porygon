#ifndef CHATOT_GUARD
#define CHATOT_GUARD

////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

typedef enum ChatotSeverity
{
    // Should print helpful debug information.
    CHATOT_SEVERITY_DEBUG,

    // Should warn of potential errors.
    CHATOT_SEVERITY_WARNING,

    // Should warn of realized errors.
    CHATOT_SEVERITY_ERROR,

    // Should warn of errors that are not recoverable.
    // If passed to `chatot_chatter()`, then `exit(EXIT_FAILURE)` will be called.
    CHATOT_SEVERITY_FATAL
}
ChatotSeverity;

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

// Sets the minimum severity requirement for messages passed to `chatot_chatter()`.
// The default severity is `CHATOT_SEVERITY_DEBUG`.
void chatot_severity(ChatotSeverity severity);

// Prints formatted messages to `stdout`.
// Messages are prefixed with their corresponding severity.
// If a message does not meet the minimum severity requirement, then it will not be printed.
// If a message has `CHATOT_SEVERITY_FATAL`, then `exit(EXIT_FAILURE)` will be called.
void chatot_chatter(ChatotSeverity severity, const char* message, ...);

#endif // CHATOT_GUARD