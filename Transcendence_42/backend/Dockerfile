FROM python:3.10-alpine

RUN apk add --no-cache postgresql-client netcat-openbsd

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

# Expose Django port
EXPOSE 8000

CMD ["/app/init.sh"]
