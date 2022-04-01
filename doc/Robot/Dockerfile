FROM ubuntu:latest
COPY Robot.cpp /Robot.cpp
RUN apt-get update && apt-get -y install \
	g++ \
	nano
RUN g++ -o test Robot.cpp
#RUN ./test
#ENTRYPOINT ["/bin/bash"]
#CMD ["g++ "]
CMD ["./test"]