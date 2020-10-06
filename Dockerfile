FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN g++ main.cpp -o program
RUN chmod +x program
