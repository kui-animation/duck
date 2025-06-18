from setuptools import setup, Extension

setup(
    name="duck",
    ext_modules=[
        Extension(
            "duck",
            sources=["src/duck.c", "src/func.c", "src/helper.c"],  # list ALL .c files
            include_dirs=["src/inc"],               # include path for func.h
        )
    ]
)

