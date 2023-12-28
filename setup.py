from setuptools import setup, find_packages

setup(
    name='ROS2-Cognition',
    version='0.1',
    packages=find_packages(),
    install_requires=[
                'git+https://github.com/HolotypeRobotics/Cognition.git'
    ],
    scripts=[
        'src/server/server_node.py'
    ],
    package_dir={'': 'src'},
)