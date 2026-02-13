FROM gcc:latest

WORKDIR /usr/src/myapp

RUN apt-get update

RUN apt-cache search check | grep -i libcheck

RUN apt-get install -y libcheck-dev || apt-get install -y check

COPY . .

RUN make test