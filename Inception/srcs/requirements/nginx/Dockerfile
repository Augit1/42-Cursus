FROM alpine:3.20

RUN apk add --no-cache nginx openssl

RUN mkdir -p /etc/nginx/certs && \
			openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
			-keyout /etc/nginx/certs/server.key \
			-out /etc/nginx/certs/server.crt \
			-subj "/CN=${DOMAIN_NAME}"

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/wordpress.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
