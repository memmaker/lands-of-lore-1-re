"""mark.py NAME FN... : put /* NONMATCHING */ above the definitions of the given functions in src/NAME.c"""
import re, sys
p = 'src/%s.c' % sys.argv[1]; s = open(p).read()
for f in sys.argv[2:]:
    s = re.sub(r'\n(?!/\* NONMATCHING)([^\n;]*\b%s\([^\n;]*\)\n\{)' % f, lambda m: '\n/* NONMATCHING */\n' + m.group(1), s, count=1)
open(p, 'w').write(s)
