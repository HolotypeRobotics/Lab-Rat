# ROS2 as a parent image
FROM osrf/ros:humble-desktop-full

# Set the working directory in the container
WORKDIR /usr/src/app

# Install any needed packages specified in requirements.txt
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Define environment variables (if any)
# ENV VAR_NAME=value

# Run the ROS2 Python script
CMD ["ros2", "run", "cognition", "agency.py"]
