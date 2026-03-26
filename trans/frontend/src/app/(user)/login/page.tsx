'use client';
import React, { useState } from 'react';
import { useAuth } from '@/modules/user/components/AuthContext';
import { useRouter } from 'next/navigation';
import styles from './login.module.css';

export default function LoginPage() {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [isRegister, setIsRegister] = useState(false);
  const { login } = useAuth();
  const router = useRouter();

  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    const endpoint = isRegister ? 'http://localhost:8080/api/v1/auth/register' : 'http://localhost:8080/api/v1/auth/login';
    
    try {
      const res = await fetch(endpoint, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ username, password })
      });
      const data = await res.json();
      if (res.ok) {
        login(data);
        router.push('/');
      } else {
        alert(data.error);
      }
    } catch (err) {
      console.error(err);
      alert('Network error');
    }
  };

  return (
    <div className={styles.container}>
      <form onSubmit={handleSubmit} className={styles.form}>
        <h2>{isRegister ? 'Register' : 'Login'}</h2>
        <input 
          type="text" 
          placeholder="Username" 
          value={username} 
          onChange={(e) => setUsername(e.target.value)} 
          required 
          className={styles.input}
        />
        <input 
          type="password" 
          placeholder="Password" 
          value={password} 
          onChange={(e) => setPassword(e.target.value)} 
          required 
          className={styles.input}
        />
        {isRegister && (
            <input 
                type="email" 
                placeholder="Email address" 
                required 
                className={styles.input}
            />
        )}
        <button type="submit" className={styles.button}>
          {isRegister ? 'Sign Up' : 'Sign In'}
        </button>
        <p className={styles.toggle} onClick={() => setIsRegister(!isRegister)}>
          {isRegister ? 'Already have an account? Login' : `Don't have an account? Register`}
        </p>
      </form>
    </div>
  );
}