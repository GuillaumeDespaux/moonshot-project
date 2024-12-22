const express = require('express');
const admin = require('firebase-admin');
const cors = require('cors');

// Initialize Firebase Admin SDK
const serviceAccount = require('./serviceAccountKey.json');

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
});

const db = admin.firestore();

// Create Express app
const app = express();
app.use(cors());
app.use(express.json());

// Define API routes

// Get all documents from a Firestore collection
app.get('/api/:collection', async (req, res) => {
  const { collection } = req.params;

  try {
    const snapshot = await db.collection(collection).get();
    const data = snapshot.docs.map(doc => ({ id: doc.id, ...doc.data() }));
    res.status(200).json(data);
  } catch (error) {
    console.error('Error fetching data:', error);
    res.status(500).json({ message: 'Error fetching data' });
  }
});

// Get a single document by ID
app.get('/api/:collection/:id', async (req, res) => {
  const { collection, id } = req.params;

  try {
    const doc = await db.collection(collection).doc(id).get();
    if (doc.exists) {
      res.status(200).json({ id: doc.id, ...doc.data() });
    } else {
      res.status(404).json({ message: 'Document not found' });
    }
  } catch (error) {
    console.error('Error fetching document:', error);
    res.status(500).json({ message: 'Error fetching document' });
  }
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
