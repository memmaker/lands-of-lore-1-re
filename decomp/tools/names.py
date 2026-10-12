"""results/names.tsv: address name (fn_SSSS_OOOO, ovr_SSSS_OOOO, g_XXXX) -> speaking name, one pair per line.
Tools that derive addresses from symbol names call orig() first, so renamed symbols keep working."""
import os
P = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'results', 'names.tsv')


def table():
    """{address name: speaking name}"""
    t = {}
    if os.path.exists(P):
        for l in open(P):
            f = l.split()
            if len(f) >= 2 and not l.startswith('#'): t[f[0]] = f[1]
    return t


_inv = None
def orig(sym):
    """address name of sym (keeps a leading '_' / '@'); unchanged if it was never renamed"""
    global _inv
    if _inv is None: _inv = {v: k for k, v in table().items()}
    p = sym[:1] if sym[:1] in '_@' else ''
    return p + _inv.get(sym[len(p):], sym[len(p):])


def save(t):
    with open(P, 'w') as f:
        f.write('# address name -> speaking name (tools/rename.py maintains this; tools/names.py reads it)\n')
        for k in sorted(t): f.write('%s\t%s\n' % (k, t[k]))
