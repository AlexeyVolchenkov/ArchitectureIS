FROM ubuntu:latest
COPY avtomat.cpp /avtomat.cpp
RUN apt-get update && apt-get -y install \
	g++ \
	nano
RUN g++ -o test avtomat.cpp
#RUN ./test
#ENTRYPOINT ["/bin/bash"]
#CMD ["g++ "]
CMD ["./test"]