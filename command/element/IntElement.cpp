#include "IntElement.h"

void IntElement::parse(ParsingContext &args, CommandContext &ctx) const throw(ParseException) {
    std::string next = args.next();
    errno = 0;
    char *end;
    long num = strtol(next.c_str(), &end, 10); //Parses a long in base 10
    if (*next.c_str() == '\0' || *end != '\0') { //Ensures that the entire string was consumed
        throw ParseException("Input " + next + " is not an integer.");
    } else if (errno == ERANGE && (num == LONG_MAX || num == LONG_MIN) || num > max || num < min) { //Range check
        throw ParseException("Input " + next + " must be in range [" + std::to_string(min) + "," + std::to_string(max) + "]");
    }
    ctx.putArg(getName(), new int(num));
}