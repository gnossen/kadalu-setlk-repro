# Running the Repro

Modify `setlk-repro.yaml` to point to a storage class with `pv_type: Block`.

```
docker build -t ${YOUR_TAG} .
docker push ${YOUR_TAG}
sed -i 's|docker:5000/gluster-setlk-repro:6|${YOUR_TAG}|g'
kubectl apply -f setlk-repro.yaml
kubectl logs -l app=gluster-setlk-repro
```

You should see:

```
Error calling fcntl(fd, F_SETLK, &flck) : Value too large for data type
```
