def FlagsForFile( filename, **kwargs ):
    return {
        'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-std=c++17', '-O2', '-fopenmp'],
    }

