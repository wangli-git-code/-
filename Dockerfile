FROM gcc:10
COPY ./* /app/
WORKDIR /app/
RUN g++ main.cpp -o program
RUN chmod +x program
