FROM ubuntu:latest
COPY MergeRobot.cpp /MergeRoboot.cpp
RUN apt-get update && apt-get -y install \
	g++ \
	nano \
	cmake \
	make
RUN g++ -o test MergeRobot.cpp
CMD ["./test"]