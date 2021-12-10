FROM node:12-alpine as redis
WORKDIR /app
COPY . /app
RUN npm install
EXPOSE 80
ENV PORT 80
CMD ["node", "server.js"]
