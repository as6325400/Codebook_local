IMAGE_NAME="codebook"
CONTAINER_NAME="codebookLatex"

if ! docker images "$IMAGE_NAME" | grep -q "$IMAGE_NAME"; then
    echo "Building xeLatex Docker image..."
    sudo docker build -t "$IMAGE_NAME" .
else
    echo "Docker image $IMAGE_NAME already exists."
fi

echo "Running Docker container..."
sudo docker run -v "$(pwd):/compileCodebook" --name "$CONTAINER_NAME" "$IMAGE_NAME"


echo "Stopping and removing container..."
sudo docker stop "$CONTAINER_NAME"
sudo docker rm "$CONTAINER_NAME"

echo "Removing log..."
rm ./codebook.aux ./codebook.log ./codebook.toc

echo "Done."